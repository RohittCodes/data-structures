/*
    Problem statement:
    Sam is making a forest visualizer. An N-dimensional forest is represented by the pattern of size NxN filled with ‘*’.

    An N/2-dimensional forest is represented by the lower triangle of the pattern filled with ‘*’.

    For every value of ‘N’, help sam to print the corresponding N/2-dimensional forest.

    Example:
    Input:  ‘N’ = 3

    Output: 
    * 
    * *
    * * *
*/

#include <iostream>
using namespace std;

void forest(int n){
    for(int i=0; i<n; i++){ // Since, there are n number of rows
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cout<<"No. of test cases: ";
    cin>>t;
    while(t){
        int n;
        cout<<"Enter your test case: "
        cin>>n;
        forest(n);
        t--;
    }
    return 0;
}