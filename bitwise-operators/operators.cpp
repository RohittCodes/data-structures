#include <iostream>
using namespace std;

int main(){
    int a = 4; //100
    int b = 6; //110

    cout<<"a&b: "<<(a&b)<<endl; //100
    cout<<"a|b: "<<(a|b)<<endl; //110
    cout<<"~a: "<<~a<<endl; //[1]111....111011 then 2's complement and msb 1 for negative
    cout<<"a^b: "<<(a^b)<<endl; //010
    
    return 0;
}