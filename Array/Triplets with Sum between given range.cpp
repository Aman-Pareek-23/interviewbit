********problem*************
Triplets with Sum between given range
Medium

59

83

Add to favorites
Given an array of real numbers greater than zero in form of strings.

Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 

 Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.


**********************solution*************
int Solution::solve(vector<string> &A) {
    int i=0;
    int j=A.size()-1;
    sort(A.begin(),A.end());
    while(i<j-1)
    {
        int mid=(i+j)/2;
        double x=stof(A[i]);
        double y=stof(A[mid]);
        double z=stof(A[j]);
        double sum=x+y+z;
        if(sum>=2)
        {
            j--;
        }
        else if(sum<=1)
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
