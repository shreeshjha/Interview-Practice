#include <iostream>
#include <vector>

using namespace std;

const int N = 50005;
vector<int> g[N];
int dp[N];

void solveCase(int caseNumber) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dp[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int ansNode = 0;
    int maxDp = -1;

    for (int i = 1; i <= n; i++) {
        int node = i, depth = 0;
        while (g[node].size() == 1) {
            node = g[node][0];
            depth++;
        }
        dp[i] = depth + dp[node];
        if (dp[i] > maxDp || (dp[i] == maxDp && i < ansNode)) {
            maxDp = dp[i];
            ansNode = i;
        }
    }

    cout << "Case " << caseNumber << ": " << ansNode << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solveCase(i);
    }
    return 0;
}

