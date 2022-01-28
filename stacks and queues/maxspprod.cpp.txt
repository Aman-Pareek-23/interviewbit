MAXSPPROD
Medium

70

39

Add to favorites
Problem Description

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

NOTE:  As the answer can be large, output your answer modulo 109 + 7.



Problem Constraints
1 <= N <= 105
 
1 <= A[i] <= 109



Input Format
First and only argument is an integer array A.

***************************Question***********************

Output Format
Return an integer denoting the maximum special product of any integer.



Example Input
Input 1:

 A = [1, 4, 3, 4]
Input 2:

 A = [10, 7, 100]


Example Output
Output 1:

 3
Output 2:

 0


Example Explanation
Explanation 1:

 For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
 So, the ans is 1*3 = 3.
 
Explanation 2:

 There is not any integer having maximum special product > 0. So, the ans is 0.
 
 ***************** SOlution****************
 int Solution::maxSpecialProduct(vector<int> &A) {
	int n = A.size();
	vector<int> LeftSpecialValue(n,0),RightSpecialValue(n,0);
	stack<int> leftCalc;
	leftCalc.push(0);
	LeftSpecialValue[0]=0;
	for(int i=1;i<n;i++){
		while(!leftCalc.empty()){
			if(A[leftCalc.top()]>A[i]) break;
			leftCalc.pop();
		}
		LeftSpecialValue[i] = (leftCalc.empty())?0:leftCalc.top();
		leftCalc.push(i);
	}
	stack<int> rightCalc;
	rightCalc.push(n-1);
	RightSpecialValue[n-1]=0;
	for(int i=n-2;i>=0;i--){
		while(!rightCalc.empty()){
			if(A[rightCalc.top()]>A[i]) break;
			rightCalc.pop();
		}
		RightSpecialValue[i] = (rightCalc.empty())?0:rightCalc.top();
		rightCalc.push(i);
	}
	long long mx = -1;
	for(int i=0;i<n;i++){
		mx=max(mx,LeftSpecialValue[i]*1LL*RightSpecialValue[i]);
	}
	return mx%1000000007;
}
