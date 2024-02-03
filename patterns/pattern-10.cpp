/*
Problem statement
Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the N-Star Rotated Triangle.

Example:
Input: ‘N’ = 3

Output: 

*
**
***
**
*
*/

#include <iostream>
using namespace std;

void forest(int n){
    for(int i=1; i<=2*n-1; i++){
        int stars = i;
        if(i>n) stars = 2*n-i;
        for(int j=1; j<=stars; j++){
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