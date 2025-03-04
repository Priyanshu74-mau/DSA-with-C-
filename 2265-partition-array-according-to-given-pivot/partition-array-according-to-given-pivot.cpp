class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small,equal,greater;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<pivot)
            {
                small.push_back(nums[i]);
            }
            else if(nums[i]==pivot)
            {
                equal.push_back(nums[i]);
            }
            else
            {
                greater.push_back(nums[i]);
            }
        }
        vector<int>ans;
        ans.insert(ans.end(),small.begin(),small.end());
        ans.insert(ans.end(),equal.begin(),equal.end());
        ans.insert(ans.end(),greater.begin(),greater.end());

        return ans;
    }
};