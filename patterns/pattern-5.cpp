/*
Problem statement
Sam is planting trees on the upper half region (separated by the left diagonal) of the square shared field.

For every value of ‘N’, print the field if the trees are represented by ‘*’.

Example:
Input: ‘N’ = 3

Output: 
* * *
* *
*
*/

#include <iostream>
using namespace std;

void forest(int n){
    for(int i=n; i>0; i--){
        for(int j=i; j>0; j--){
            cout<<"* ";
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