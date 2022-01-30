*********************Numbers of length N and value less than K***************
Hard

73

25

Add to favorites
Problem Description

Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.
NOTE: All numbers can only have digits from the given set.  

Examples:

Input:
  0 1 5

  1

  2

Output:

  2 (0 and 1 are possible)  


Input:
  0 1 2 5

  2

  21

Output:
  5 (10, 11, 12, 15, 20 are possible)

Constraints:

1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9

*****************Solution****************
int getMin(int B){
    if(B==1) return 0;

    int result=1;

    while(B>1){ result*=10;B--;}

    return result;
}

int getMax(int B){
    int result =0;

    while(B>0){ result*=10;result+=9;B--;}

    return result;
}

int Solution::solve(vector<int> &A, int B, int C) {
    if(A.size()==0) return 0;

    //if B is greater than length of C no solution is possible
    if(C<getMin(B)) return 0; 

    int reverseC = 0,result=0,n=A.size();

    //if B is less , all possible numbers will be less than C
    if(C>getMax(B)){
        result += pow(n,B);
        //remove the ones with leading zeroes
        if(A[0]==0 && B>1) result -= pow(n,B-1);
        return result;
    }

    while(C>0){ reverseC*=10;reverseC+=(C%10);C/=10;}

    for(int i=0;i<B;i++,reverseC=reverseC/10){
        int digit = reverseC%10,j=0;
        
        while(j<A.size() && A[j]<digit){
            result += pow(n,B-i-1);j++;
        } 
        if(j>=A.size() || A[j]>digit) break;
    }

    //remove the ones with leading zeroes
    if(A[0]==0 && B>1){ result -= pow(n,B-1);}

    return result;
}
