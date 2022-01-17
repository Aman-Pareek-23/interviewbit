Problem Description

Given a number A in a form of string.

You have to find the smallest number that has same set of digits as A and is greater than A.

If A is the greatest possible number with its set of digits, then return -1.



Problem Constraints
 1 <= A <= 10100000

 A doesn't contain leading zeroes.



Input Format
First and only argument is an numeric string denoting the number A.



Output Format
Return a string denoting the smallest number greater than A with same set of digits , if A is the largest possible then return -1.



Example Input
Input 1:

 A = "218765"
Input 2:

 A = "4321"


Example Output
Output 1:

 "251678"
Output 2:

 "-1"


Example Explanation
Explanation 1:

 The smallest number greater then 218765 with same set of digits is 251678.
Explanation 2:

 The given number is the largest possible number with given set of digits so we will return -1.
*************Solution*****************
string Solution::solve(string A) {
    int p=0,n=A.size(); 
    if(n<2)
    return "-1"; 
    for(int i=n-1;i>0;i--) 
    { 
        if(A[i]<=A[i-1])
        continue; 
        else 
        { 
            p=i; 
            break; 
        } 
    } 
    if(p==0)
    return "-1";
    string s=A.substr(p,n-p),r=A.substr(0,p); 
    reverse(s.begin(),s.end()); 
    s=r+s; 
    for(int i=p;i<n;i++) 
    { 
        if(s[p-1]<s[i]) 
        { 
            swap(s[i],s[p-1]); 
            break; 
        } 
    } 
return s; 
}

********Solution****************
string Solution::solve(string A) {

if(next_permutation(A.begin(), A.end()))
{
    return A;
}
return "-1";
}
