#include <iostream>
using namespace std;

int main(){
    int a = 7;

// If done individually | If done whole at once
    cout<<"a++: "<<(a++)<<endl; // post inc -> 7 | 7 (after it a=8)
    cout<<"a--: "<<(a--)<<endl; // post dec -> 7 | 8 (after it a=7)
    cout<<"++a: "<<(++a)<<endl; // pre inc -> 8 | 8 (after it a=8)
    cout<<"--a: "<<(--a)<<endl; // pre dec -> 6 | 7

    return 0;
}