//Write a program to Print Cube of first N Natural number in Reverse order using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Print Cube of first N natural number in Reverse order.
void recursiveFunction(int n){
    if(n == 0){
        return;
    }else{
        cout<<(n* n* n)<<endl;
        recursiveFunction(n- 1);
    }
}

int main(){
    cout<<"Print Cube of first N Natural number in Reverse order using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    recursiveFunction(n);
    
    //getch();
    return(0);
}