class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int n= nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int k=j+1;
                int l=n-1;
                int curtarget = target-nums[i]-nums[j];

                while(k<l)
                {
                    if(nums[k]+nums[l]== curtarget)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});

                        while(k<l && nums[k]==nums[k+1]) k++;
                        while(k<l && nums[l]== nums[l-1]) l--;
                        k++;
                        l--;
                    }
                    else if(nums[k]+nums[l] < curtarget)
                    {
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        } 
        return ans;
    }
};
