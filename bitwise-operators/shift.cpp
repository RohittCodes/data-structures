#include <iostream>
using namespace std;

// left & right shift for +ve numbers padding with 0
// left & right shift for -ve numbers padding is compiler dependent
int main(){
    int a = 10; //1010

    cout<<"(a>>1): "<<(a>>1)<<endl; // right shift by one -> 0101(5)
    cout<<"(a<<1): "<<(a<<1)<<endl; // left shift by one -> 10100(20)

    return 0;
}