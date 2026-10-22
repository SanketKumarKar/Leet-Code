class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> rev(nums.rbegin(), nums.rend());

        // dist[type][shift] = minimum operations to reach state
        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q; //bfs ke liye

        dist[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [type, shift] = q.front();
            q.pop();

            // Check whether the current state is sorted
            bool sorted = true;

            for (int i = 0; i < n; i++) {
                int value;

                if (type == 0)
                    value = nums[(i + shift) % n];
                else
                    value = rev[(i + shift) % n];

                if (value != i) { //given hai 0 to n-1 hi nums hai
                    sorted = false;
                    break;
                }
            }

            if (sorted)
                return dist[type][shift];

            // Operation 1: Rotate left by one
            int nextShift = (shift + 1) % n;

            if (dist[type][nextShift] == -1) {
                dist[type][nextShift] = dist[type][shift] + 1;
                q.push({type, nextShift});
            }

            // Operation 2: Reverse the entire array
            int nextType = 1 - type;
            int reverseShift = (n - shift) % n;

            if (dist[nextType][reverseShift] == -1) {
                dist[nextType][reverseShift] = dist[type][shift] + 1;
                q.push({nextType, reverseShift});
            }
        }

        return -1;
    }
};