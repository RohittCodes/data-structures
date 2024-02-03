/*
Problem statement
Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the Reverse N-Star Triangle.

Example:
Input: ‘N’ = 3

Output: 

*****
 ***
  *
*/

#include <iostream>
using namespace std;

void forest(int n){
    for(int i=n; i>0; i--){
        for(int j=0; j<n-i; j++){
            cout<<" ";
        }
        for(int j=0; j<2*i-1; j++){
            cout<<"*";
        }
        cout<<endl;
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