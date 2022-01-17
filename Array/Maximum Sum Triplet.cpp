***********Question*************

Problem Description

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.



Problem Constraints
3 <= N <= 105.

1 <= A[i] <= 108.



Input Format
First argument is an integer array A.



Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.



Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
Input 2:

 A = [1, 2, 3]


Example Output
Output 1:

 16
Output 2:

 6


Example Explanation
Explanation 1:

 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
Explanation 2:

 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6
   
   **********Answer***********
   
   int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int> right(n);
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)right[i]=A[i];
        else right[i]=max(right[i+1],A[i]);
    }
    set<int> s;
    s.insert(A[0]);
    for(int i=1;i<n;i++)
    {
        s.insert(A[i]);
        auto it=s.find(A[i]);
        if(it!=s.begin()&& right[i]!=A[i])
        ans=max(ans,(*--it)+A[i]+right[i]);
    }
    return ans;
}
