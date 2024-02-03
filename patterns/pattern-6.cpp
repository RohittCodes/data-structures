/*
Problem statement
Aryan and his friends are very fond of the pattern. For a given integer ‘N’, they want to make the Reverse N-Number Triangle.

Example:
Input: ‘N’ = 3

Output: 

1 2 3
1 2
1
*/

#include <iostream>
using namespace std;

void forest(int n){
    for(int i=n; i>0; i--){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
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