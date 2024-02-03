#include <iostream>
using namespace std;

int main(){
    int num = 20;
    cout<<num<<endl;
    //This is the referencing variable num which reference the memory location of 20.
    cout<<&num<<endl;
    //This is where our num variable references to in the symbol table. The value 20 is stored here.
    return 0;
}