class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(!(nums[i]&1))
                sum += nums[i];
        }
        vector<int> ans;
        for(int i = 0;i < queries.size();i++){
            int val = queries[i][0];
            int index = queries[i][1];
            if (nums[index] % 2 == 0) {
                sum -= nums[index];
            }
            nums[index] += val;
            if (nums[index] % 2 == 0) {
                sum += nums[index];
            }
            ans.emplace_back(sum);
        }
        return ans;
    }
};