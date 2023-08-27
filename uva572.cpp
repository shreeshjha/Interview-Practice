 /* 
The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits.
GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides
the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to
determine whether or not the plot contains oil.
A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the
same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to
determine how many different oil deposits are contained in a grid.

Input
The input file contains one or more grids. Each grid begins with a line containing m and n, the number
of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input;
otherwise 1 ≤ m ≤ 100 and 1 ≤ n ≤ 100. Following this are m lines of n characters each (not counting
the end-of-line characters). Each character corresponds to one plot, and is either ‘*’, representing the
absence of oil, or ‘@’, representing an oil pocket.

Output
For each grid, output the number of distinct oil deposits. Two different pockets are part of the same
oil deposit if they are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain
more than 100 pockets.

Sample Input
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

Sample Output
0
1
2
2
 */

/*  How to approach this problem -
 *  So what we have here is classical problem of finding connected component.
 *  I am going to use dfs to find no of distinct oil ports
 *
 *  Here's step-by-step approach to solve this problem:
 *  1) Read the input 
 *    -Read the number of rows "m" and columns "n";
 *    -If m == 0 then terminate the program
 *  2) Create a DFS function and maintain visited index (check for boundary condition -> this is important)
 *  3) For each separate DFS call count it as distinct oil ports 
 */ 

 #include <bits/stdc++.h>
 using namespace std;
 
 vector<vector<char>> graph(101, vector<char>(101));
 vector<vector<bool>> visited(101, vector<bool>(101, false));  
 vector<int> result;
 int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
 int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
 bool check_boundary(int i, int j, int m, int n) {
   if(i < 0 || j < 0 || i >= m || j >= n) {
     return false;
   }
   return true;
 }

 bool isValid(vector<vector<char>> &graph, int i, int j) {
   if(graph[i][j] == '*') {
     return false;
   }
   else if(visited[i][j] == true) {
     return false;
   }
   return true;
 }

 void dfs(vector<vector<char>> &graph, vector<vector<bool>> &visited, int i, int j) {
   if((!check_boundary(i, j, graph.size(), graph[0].size())) || (!isValid(graph, i, j))) {
      return;
   } 

   visited[i][j] = true;
   for(int k = 0; k < 8; k++) {
      int newRow = i + dr[k];
      int newCol = j + dc[k];

      dfs(graph, visited, newRow, newCol);
   }  
 }

 int main() {
   
   int m, n;
   while((cin >> m >> n) && (m != 0 && n!= 0)) {
      graph.resize(m, vector<char>(n));
      visited.resize(m, vector<bool>(n, false)); 

     for(int i = 0; i < m; i++) {
       for(int j = 0; j < n; j++) {
         cin >> graph[i][j];
       }
     }
     int oil_port = 0;
     for(int i = 0; i < m; i++) {
       for(int j = 0; j < n; j++) {
         if(!visited[i][j] && graph[i][j] == '@') {
           dfs(graph, visited, i, j);
           oil_port++;
         }
       }
     }
     cout << oil_port << "\n";
   }
   cout << endl;
   return 0;
 }
