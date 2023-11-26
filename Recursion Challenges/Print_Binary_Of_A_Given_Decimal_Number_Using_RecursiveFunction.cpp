//Write a program to Print binary of a given decimal number using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

int x;
//Recusive Funtion to calculate binary of a given decimal number.
void recursiveFunction(int n){
    if(x == 0){
        cout<<x;
    }else{
        if(n == 0){
        return;
        }
        int remender, quotient;
        remender= n% 2;
        quotient= n/ 2;
        recursiveFunction(quotient);
        cout<<remender;
    }
}

int main(){
    cout<<"Print binary of a given decimal number using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;
    x= n;

    recursiveFunction(n);
    
    //getch();
    return(0);
}