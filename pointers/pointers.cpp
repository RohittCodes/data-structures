#include <iostream>
using namespace std;

int main(){
    int num = 20; //A variable to hold our data
    int *ptr = &num; //Creating a pointer to int and adding address to it.
    cout<<num<<endl; //Printing out num value
    cout<<ptr<<endl; //Priniting out the address value
    *ptr = (*ptr)+1;
    cout<<*ptr<<endl; //Printing the value of num
    cout<<num<<endl;
    cout<<&num<<endl; //Printing out the address of num
    return 0;
}