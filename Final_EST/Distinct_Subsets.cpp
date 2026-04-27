#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> distinctSubsets(vector<int> arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long totalMasks = 1LL << n;

        set<vector<int>> uniqueSubsets;

        for (long long mask = 0; mask < totalMasks; mask++) {
            vector<int> current;
            for (int i = 0; i < n; i++) {
                if (mask & (1LL << i)) {
                    current.push_back(arr[i]);
                }
            }
            uniqueSubsets.insert(current);
        }

        vector<vector<int>> result(uniqueSubsets.begin(), uniqueSubsets.end());
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    vector<vector<int>> subsets = sol.distinctSubsets(arr);

    for (auto &subset : subsets) {
        cout << "[";
        for (int i = 0; i < (int)subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < (int)subset.size()) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}