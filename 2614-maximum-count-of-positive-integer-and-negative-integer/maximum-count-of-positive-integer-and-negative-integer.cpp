class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countN=0;
        int countP=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
            {
                countP++;
            }
            else if(nums[i]<0)
            {
                countN++;
            }
        }
        return max(countP,countN);
    }
};