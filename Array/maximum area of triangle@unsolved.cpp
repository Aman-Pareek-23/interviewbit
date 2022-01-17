************Question*********************
Problem Description

Given a character matrix of size N x M in the form of a string array A of size N where A[i] denotes ith row.

Each character in the matrix consists any one of the following three characters {'r', 'g', 'b'} where 'r' denotes red color similarly 'g' denotes green color and 'b' denotes blue color.

You have to find the area of the largest triangle that has one side parallel to y-axis i.e vertical and the color of all three vertices are different.

NOTE:

If the area comes out to be a real number than return the ceil of that number.


Problem Constraints
2 <= N, M <= 103

A[i][j] = 'r' or A[i][j] = 'g' or A[i][j] = 'b'



Input Format
First and only argument is an string array A of size N denoting the 2D character matrix.



Output Format
Return a single integer denoting the area of the largest triangle that has one side parallel to y-axis i.e vertical and the color of all three vertices are different.

If the area comes out to be a real number than return the ceil of that number.



Example Input
Input 1:

 A = ["rrrrr", "rrrrg", "rrrrr", "bbbbb"]
Input 2:

 A = ["rrr", "rrr", "rrr", "rrr"]


Example Output
Output 1:

 10
Output 2:

 0


Example Explanation
Explanation 1:

 The maximum area of triangle is 10.
 Triangle coordinates are (0,0) containing r, (1,4) containing g, (3,0) containing b.
 
Explanation 2:

 All cells have same color so no triangle possible so we will return 0
   
   ************solution****************
   
int area(int col, int x1, int x2, int right, int left) {
    if(x1 == -1 || col == -1 || x2 == -1 || (right == -1 && left == -1)) return 0;
    if(x1 >= x2 || right <= col && left >= col) return 0;
    return max(ceil(0.5 * (x2 - x1 + 1) * (right - col + 1)), ceil(0.5 * (x2 - x1 + 1) * (col - left + 1)));
}
int Solution::solve(vector<string> &A) {
     int n = A.size(), m = A[0].size(), i, j, k;
    
    string color = "rgb";
    
    int first[3][m], last[3][m], right[3] = {-1, -1, -1}, left[3] = {-1, -1, -1};
    
    for(i=0;i<3;i++) for(j=0;j<m;++j) 
        first[i][j] = last[i][j] = -1;
    for(j=0;j<m;++j) for(i=0;i<n;++i) for(k=0;k<3;k++) {
        if(A[i][j] == color[k] && first[k][j] == -1) first[k][j] = i;
        if(A[i][j] == color[k] && left[k] == -1) left[k] = j;
    }
    for(j=m-1;j>=0;--j) for(i=n-1;i>=0;--i) for(k=0;k<3;k++) {
        if(A[i][j] == color[k] && last[k][j] == -1) last[k][j] = i;
        if(A[i][j] == color[k] && right[k] == -1) right[k] = j;
    }
    
    int ans = 0;
    for(j=0;j<m;++j)  for(k=0;k<3;++k) 
        ans = max({ ans, 
                    area(j, first[k][j], last[(k+1)%3][j], right[(k+2)%3], left[(k+2)%3]),
                    area(j, first[k][j], last[(k+2)%3][j], right[(k+1)%3], left[(k+1)%3])
                 });

    return ans;
}
