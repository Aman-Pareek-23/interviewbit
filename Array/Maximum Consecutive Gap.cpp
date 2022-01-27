***********************Maximum Consecutive Gap**********************************
Medium

91

26

Add to favorites
Asked In:
HUNAN ASSET
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
********************Solution1*****************
int Solution::maximumGap(const vector<int> &A) {
    
    if(A.size()<2)
    return 0;
    
    int diff=0;
    int i;
    int max=0;
    
    vector<int>*temp=(vector<int>*)&A;
    sort(temp->begin(),temp->end());
    
    //sort(A.begin(),A.end());
    
    for(i=0;i<A.size()-1;i++)
    {
        diff=A[i+1]-A[i];
        
        if(max<diff)
        max=diff;
    }
    return max;
}

*****************Solution2*******************
int Solution::maximumGap(const vector<int> &v) {
    int maxval=*max_element(v.begin(),v.end()),minval=*min_element(v.begin(),v.end());
    int n=v.size();
    if(n<2)
    return 0;
    vector<int> bmax(n-1,INT_MIN);
    vector<int> bmin(n-1,INT_MAX);
    float divide=(float)(maxval-minval)/(float)(n-1);
    for(int i=0;i<n;i++)
    {
        if(minval==v[i] || maxval==v[i]) continue;
        int index=(v[i]-minval)/divide;
        bmax[index]=max(bmax[index],v[i]);
        bmin[index]=min(bmin[index],v[i]);
    }
    int prev=minval;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(bmin[i]==INT_MAX) continue;
        ans=max(ans,bmin[i]-prev);
        prev=bmax[i];
    }
    ans=max(ans,maxval-prev);
    return ans;
}
