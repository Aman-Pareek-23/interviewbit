*************Balance Array****************
Easy

91

26

Add to favorites
Asked In:
DUNZO
Problem Description

Given an integer array A of size N. You need to count the number of special elements in the given array.

A element is special if removal of that element make the array balanced.

Array will be balanced if sum of even index element equal to sum of odd index element.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the count of special elements.



Example Input
Input 1:

 A = [2, 1, 6, 4]
Input 2:

 A = [5, 5, 2, 5, 8]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 After deleting 1 from array : {2,6,4}
    (2+4) = (6)
 Hence 1 is the only special element, so count is 1
Explanation 2:

 If we delete A[0] or A[1] , array will be balanced
    (5+5) = (2+8)
 So A[0] and A[1] are special elements, so count is 2.
 
**************Solution*************
int Solution::solve(vector<int> &A) {
int n=A.size();
if(n==0)
    return 0;
vector<pair<int,int> > left_sum(n),right_sum(n);
left_sum[0].first=A[0];
left_sum[0].second=0;
for(int i=1;i<n;i++)
{
    if(i%2==0)
    {
    left_sum[i].first=left_sum[i-1].first+A[i];
    left_sum[i].second=left_sum[i-1].second;
    }
    else
    {
    left_sum[i].first=left_sum[i-1].first;
    left_sum[i].second=left_sum[i-1].second+A[i];
    }
}
if(n%2==0){
right_sum[n-1].first=0;
right_sum[n-1].second=A[n-1];
}
else
{
right_sum[n-1].first=A[n-1];
right_sum[n-1].second=0;
}
for(int i=n-2;i>=0;i--)
{
if(i%2==0)
{
right_sum[i].first=right_sum[i+1].first+A[i];
right_sum[i].second= right_sum[i+1].second;
}
else
{
right_sum[i].first=right_sum[i+1].first;
right_sum[i].second= right_sum[i+1].second+A[i];
}
}
int count=0;
int even=0,odd=0;
for(int i=0;i<n;i++)
{
if(i!=0)
{
even=left_sum[i-1].first;
odd=left_sum[i-1].second;
}
if(i%2==0)
{
int v1=right_sum[i].first-A[i];
int v2=right_sum[i].second;
even+=v2;
odd+=v1;
}
else
{
int v1=right_sum[i].first;
int v2=right_sum[i].second-A[i];
even+=v2;
odd+=v1;
}
if(even==odd)
count++;
}
return count;
}
