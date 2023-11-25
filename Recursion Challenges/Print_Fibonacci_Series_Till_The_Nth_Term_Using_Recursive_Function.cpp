//Write a program to Print Fibonacci series till the Nth Term using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
#include"string.h"
using namespace std;

//Recusive Funtion to Print Fibonacci series till the Nth Term.
void recursiveFunction(int n){
    if(n == 0 || n== 1){
        return;
    }
    int temp= (n-1)+ (n- 2);
    recursiveFunction(n- 1);
}

int main(){
    cout<<"Print Fibonacci series till the Nth Term using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    recursiveFunction(n);
    
    //getch();
    return(0);
}