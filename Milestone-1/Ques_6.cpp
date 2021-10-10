class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=m[nums[i]]+1;
        for(int i=0;i<nums.size();i++)
            if(m[nums[i]]>nums.size()/2)
                return nums[i];
        return -1;*/
        /*for(int i=0;i<nums.size();i++)
        {
            int count=0;
            int num=nums[i];
            for(int j=0;j<nums.size();j++)
            {
                if(num==nums[j])
                    count++;
            }
            if(count>nums.size()/2)
                return num;
        }
        return -1;*/
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
