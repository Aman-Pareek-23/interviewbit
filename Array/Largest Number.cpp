***************Largest Number****************
Medium

223

38

Add to favorites
Asked In:
AMAZON
GOLDMAN SACHS
MICROSOFT
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

***********Solution*************
static bool compr(string X,string Y)
{
return (X+Y)>(Y+X);
}

string Solution::largestNumber(const vector<int> &A) {
vector<string> str;
int count=0;
for(int i=0;i<A.size();i++)
str.push_back(to_string(A[i]));
sort(str.begin(),str.end(),compr);
string S;
for(int i=0;i<str.size();i++)
S+=str[i];

if(S[0]=='0')
return "0";
return S;
}
