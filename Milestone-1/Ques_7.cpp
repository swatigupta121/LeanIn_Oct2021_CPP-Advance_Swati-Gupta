class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1,k=0;
        if(nums.size()==1)
            return 1;
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]==nums[j])
                j++;
            else
            {
                nums[++i]=nums[j];
            }
            k=i+1;
        }
        return k;
    }
};
