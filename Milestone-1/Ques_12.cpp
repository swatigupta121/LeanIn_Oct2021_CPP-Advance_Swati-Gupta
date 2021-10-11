class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
      
        int count=0;
        set<int> s;
 
        for (int i = 0; i < n; i++)
            s.insert(a[i]);
     
        for (int i = 0; i < m; i++)
            if (s.find(b[i]) != s.end())
                count++;
        return count;
    }
};
