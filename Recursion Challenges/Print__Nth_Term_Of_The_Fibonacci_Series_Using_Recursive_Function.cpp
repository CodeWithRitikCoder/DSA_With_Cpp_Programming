//Write a program to Print Nth term Fibonacci series using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Print Nth term Fibonacci series.
int recursiveFunction(int n){
    if(n == 0 || n== 1){
        return n;
    }else{
        return (recursiveFunction(n- 1)+ recursiveFunction(n- 2));
    }
}

int main(){
    cout<<"Print Nth term Fibonacci series using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    int nThTermOfFibonacciSeries= recursiveFunction(n);
    cout<<"The "<<n<<"th term of Fibonacci Series is : "<<nThTermOfFibonacciSeries;
    
    //getch();
    return(0);
}