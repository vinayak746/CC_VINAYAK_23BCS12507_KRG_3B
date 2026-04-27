#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> floydWarshall(vector<vector<int>> dist) {
        int n = dist.size();
        const int INF = 1e9;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        return dist;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) dist[i][j] = 1e9;
        }
    }

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    Solution sol;
    vector<vector<int>> ans = sol.floydWarshall(dist);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == 1e9) cout << -1;
            else cout << ans[i][j];
            if (j + 1 < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}