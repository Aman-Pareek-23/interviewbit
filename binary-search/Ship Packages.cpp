***********Capacity To Ship Packages Within B Days*********************
Medium

13

0

Add to favorites
Asked In:
AMAZON
Problem Description
 
 

A conveyor belt has packages that must be shipped from one port to another within B days.

The ith package on the conveyor belt has a weight of A[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within B days.



Problem Constraints
1 <= B <= |A| <= 5 * 105
1 <= A[i] <= 105


Input Format
First argument is array of integers A denoting the weights.

Second argument is the integer B denoting the number of days. 



Output Format
Return the least weight capacity of the ship.


Example Input
Input 1:
A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B = 5
Input 2:

A = [3, 2, 2, 4, 1, 4]
B = 3


Example Output
Ouput 1:
15
Ouput 2:

6


Example Explanation
Explanation 1:
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and 
splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Explanation 2:

A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

******************Solution*****************
bool sol_possible(vector<int> &A, int B, int ans){
    int n = A.size();
    int sum = 0;
    int days_req = 1;
    for(int i=0; i<n; i++){
        sum+=A[i];
        if (sum>ans){
            days_req++;
            sum=A[i];
        }
        if (days_req>B) return false;
    }
    return true;
    
}
int Solution::solve(vector<int> &A, int B) {
    
    int maxelem = INT_MIN;
    int sum = 0;
    int n = A.size();
    for(int i=0; i<n; i++){
        maxelem = max(maxelem, A[i]);
        sum += A[i];
    }
    int lo = maxelem, hi = sum;
    int res = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (sol_possible(A, B, mid)){
            hi = mid-1;
            res = mid;
        }
        else lo = mid+1;
    }
    return res;
}
