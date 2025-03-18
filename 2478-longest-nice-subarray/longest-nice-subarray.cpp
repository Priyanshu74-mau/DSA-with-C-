class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int n=nums.size();
       int ans=0;
       // time complexity is O(n^2)
    //    for(int i=0; i<n; i++)
    //    {   
    //     int mask=0;
    //     for(int j=i; j<n; j++)
    //     {
    //         if((mask & nums[j]) != 0)
    //         {
    //             break;
    //         }
    //         ans=max(ans,j-i+1);

    //         mask=(mask | nums[j]);
    //     }
    //    }
    //    return ans; 

    // using sliding window O(n)
      int i=0;
      int j=0;
      int mask=0;
      while(j<n)
      {
         while((mask & nums[j]) != 0)
         {
            mask=(mask ^ nums[i]);
            i++;
         }
         ans=max(ans,j-i+1);
         mask= (mask | nums[j]);
         j++;
       }
      return ans;
    }
};