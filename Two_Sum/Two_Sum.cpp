class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp;
        vector<int> results;
        for(int i = 0 ; i < nums.size(); i++){
            temp = target - nums[i];
            for(int j = i + 1 ; j < nums.size(); j++){
                if(temp == nums[j]){
                    results.push_back(i);
                    results.push_back(j);
                    return results;
                }
            }
        }
        return results;
    }
};