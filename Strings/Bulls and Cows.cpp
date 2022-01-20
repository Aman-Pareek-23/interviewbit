*********************Bulls and Cows*******************************
Medium

7

4

Add to favorites
Asked In:
AMAZON
Problem Description
 
 

 You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. 
Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls. 
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.



Problem Constraints
1 <= secret.length, guess.length <= 100000
secret.length == guess.length
secret and guess consist of digits only.


Input Format
First argument is string denoting secret string 


Second argument is string denoting guess string 



Output Format
Return the hint for you friend's guess.


Example Input
Input 1:
secret = "1807", guess = "7810"
Input 2:

secret = "1123", guess = "0111"


Example Output
Ouput 1:
"1A3B"
Ouput 2:

"1A1B"


Example Explanation
Explanation 1:
Bulls are connected with a '|':
"1807"
  |
"7810"
Explanation 2:

Bulls are connected with a '|' 
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since 
the non-bull digits can only be rearranged to allow one 1 to be a bull.

**********Solution************

string Solution::solve(string A, string B) {
    int size = 0;
    int str[10] = {0};
    int temp[10] = {0};
    while(A[size]!='\0') {
        str[A[size]-'0']++;
        size++;
    }
    for(int i = 0; i<10; i++) {
        temp[i] = str[i];
    }
    int bull = 0, cows = 0;
    for(int i = 0; i<size; i++) {
        if(A[i] == B[i]) {
            bull++;
            str[A[i]-'0']--;
        }
        temp[B[i]-'0']--;
    }
    int flag = 7;
    for(int i=0; i<10; i++) {
        if(temp[i]>=0) {
            int diff = str[i] - temp[i];
            cows+=diff;
            // char sol[2];
            // sol[0] = temp[i]+'0';
            // sol[1] = '\0';
            // if(flag==0)
            //     return sol;
            // flag--;
        }
        else{
            cows+=str[i];
            // char sol[2];
            // sol[0] = i+'0';
            // sol[1] = '\0';
            // if(flag==0)
            //     return sol;
            // flag--;
        }
        // if(diff>=0) {
            
        // }
    }
    int digB=0, digC=0, tb = bull, tc = cows;
    while(tb){
        digB++;
        tb/=10;
    }
    while(tc){
        digC++;
        tc/=10;
    }
    int tens=10, index = digB;
    char soln[100];
    int db = digB, bu = bull;
    for(int i=0; i<db; i++) {
        soln[digB-1] = bu%tens+'0';
        //tens*=10;
        bu/=10;
        digB--;
    }
    if(bull == 0) {
        soln[index] = '0';
        index++;
    }
    //soln[0] = bull+'0';
    soln[index] = 'A';
    //soln[2] = cows+'0';
    tens = 10;
    int newInd = index+digC;
    // soln[2] = cows+'0';
    // soln[3] = '\0';
    // return soln;
    int dc = digC, co = cows;
    for(int i=0; i<dc; i++) {
        soln[index + 1 + digC - 1] = co%tens+'0';
        // soln[index + 1 + digC] = '\0';
        // return soln;
        // if(i==1) {
        //     soln[2] = index + 1 + digC -1 +'0';
        //     soln[4] = '\0';
        //     return soln;
        // }
        //tens*=10;
        co/=10;
        digC--;
    }
    // soln[4] = '\0';
    // return soln;
    if(cows == 0) {
        soln[newInd+1] = '0';
        newInd++;
    }
    soln[newInd + 1] = 'B';
    soln[newInd + 2] = '\0';
    return soln;
}
