/*
Problem statement
Aryan and his friends are very fond of the pattern. For a given integer ‘N’, they want to make the N-Binary Number Triangle.

You are required to print the pattern as shown in the examples below.

Example:
Input: ‘N’ = 3

Output: 

1
0 1
1 0 1
*/

#include <iostream>
using namespace std;

void forest(int n){
    int count = 0;
    for(int i=0; i<n; i++){
        string s="";
        for(int j=0; j<=i; j++){
            if(j==0){
                if(count%2==0) {cout<<"1"; s[j]='1';} else {cout<<"0"; s[j]='0';}
            }
            else{
                if(s[j-1]=='0') {cout<<"1"; s[j]='1';} else {cout<<"0"; s[j]='0';}
            }
            
        }
        cout<<endl;
        count++;
    }
}

int main(){
    int t;
    cout<<"Enter no. of test cases: ";
    cin>>t;
    while(t){
        int n;
        cout<<"Enter the test case: ";
        cin>>n;
        forest(n);
        t--;
    }
    return 0;
}