****************PRETTYPRINT***************
Add to favorites
Print concentric rectangular pattern in a 2d matrix. 

Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.

Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.

Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

*********Solution*********
vector<vector<int> > Solution::prettyPrint(int A) {
    int n=2*A-1;

vector<vector<int>> v(n, vector<int>(n,0));
  
for(int i=0; i<A; i++)
{
    for(int j=i; j<n-i; j++)
    {        
            v[i][j]= A-i;
        
            v[j][n-1-i]= A-i;
        
            v[n-1-j][i]= A-i;
            
            v[n-1-i][n-1-j]= A-i;          
    }
}    
return v;
}
