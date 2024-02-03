/*
    Problem statement: Sam is making a forest visualizer. An N-dimensional forest is represented by the pattern of size NxN filled with ‘*’.
    For every value of ‘N’, help sam to print the corresponding N-dimensional forest.

    Example:
    Input: ‘N’ = 3

    Output: 
    * * *
    * * *
    * * *

    Sample Input:
    4
    Sample Output :
    * * * *
    * * * *
    * * * *
    * * * *
*/

#include <iostream>
using namespace std;

void forest(int n){
    for(int i=0; i<n; i++){ // Since, the no. of rows is n.
        for(int j=0; j<n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int t; //no. of test cases
    cout<<"Input the number of test cases: ";
    cin>>t;
    // run no. of test cases here!
    while(t){
        int n;
        cout<<"Input the test case: ";
        cin>>n;
        forest(n);
        t--;
    }
    return 0;
}