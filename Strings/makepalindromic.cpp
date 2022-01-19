*********************Minimum Characters required to make a String Palindromic*****************************
Medium

145

19

Add to favorites
Asked In:
AMAZON
MICROSOFT
Given an string A. The only operation allowed is to insert  characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.




Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".
        
******************Solution***************

void fillLPS(string str,vector<int> &lps)//Basic LPS implementation.
{
    int n=str.size();
    int l=0;
    lps[0]=0;
    int i=1;
    while(i<n)
    {
        if(str[i]==str[l])
        {
            l++;
            lps[i]=l;
            i++;
        }
        else
        {
            if(l==0)
            {
                lps[i]=0;
                i++;
            }
            else
                l=lps[l-1];
        }
    }
}
int Solution::solve(string A)
{
    int n=A.size();
    vector<int> lps(n);//Fill the lps array
    fillLPS(A,lps);
    int max_prefix_palindrome=0;
    for(int i=0;i<n;i++)
    {
        if(lps[i]>=(i+1)/2)//If the given substring is a palindrome
            max_prefix_palindrome=max(max_prefix_palindrome,i);
    }
    return n-max_prefix_palindrome-1;
}
