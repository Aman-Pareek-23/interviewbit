*********************Find Permutation*********************
Medium

160

9

Add to favorites
Asked In:
GOLDMAN SACHS
AMAZON
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]
*************Solution**************
vector<int> Solution::findPerm(const string A, int B) {
int i=1, n=B;
vector<int> ans;
if(A[0]=='D')
ans.push_back(n--);
else
ans.push_back(i++);
if(B==2 || B==1)
return ans;
for(int j=0;j<B-2;j++)
{
    if(A[j] == 'D' && A[j+1] == 'D')
    ans.push_back(n--);
    if(A[j] == 'D' && A[j+1] == 'I')
    ans.push_back(i++);
    if(A[j] == 'I' && A[j+1] == 'D')
    ans.push_back(n--);
    if(A[j] == 'I' && A[j+1] == 'I')
    ans.push_back(i++);
}
ans.push_back(i++);
return ans;
}
