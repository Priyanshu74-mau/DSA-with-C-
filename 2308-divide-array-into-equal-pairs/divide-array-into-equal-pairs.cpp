class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int second;
        for(int arr : nums)
        {
            mp[arr]++;
        }
        for(auto &count : mp)
        {
            if(count.second % 2!=0)
            {
                return false;
            }
        }
        return true;
    }
};