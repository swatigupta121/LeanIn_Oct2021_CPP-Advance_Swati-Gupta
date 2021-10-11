class Solution{
	public:
   	vector<int>  common_digits(vector<int>nums){
   	    // Code here
   	    set<int> s;
   	    set<int> :: iterator it;
   	    for(int i=0;i<nums.size();i++)
   	    {
   	        int num=nums[i];
   	        while(num>0)
   	        {
   	            int last=num%10;
   	            num=num/10;
   	            s.insert(last);
   	        }
   	    }
   	    vector<int> res;
   	    for(it=s.begin();it!=s.end();it++)
   	        res.push_back(*it);
   	    return res;
   	}    
};
