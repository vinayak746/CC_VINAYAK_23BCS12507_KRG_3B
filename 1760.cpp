class Solution {
public:
    bool can(vector<int>& nums, int max_op, int p){
        long op = 0;

        for(int i : nums){
            op += (i - 1) / p;
        }

        return op <= max_op;
    }

    int minimumSize(vector<int>& nums, int max_op) {
        int l = 1, r = 0;

        for(int i : nums){
            r = max(r, i);
        }

        int ans = r;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(can(nums, max_op, mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};