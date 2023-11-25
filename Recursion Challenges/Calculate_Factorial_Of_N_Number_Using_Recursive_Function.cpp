//Write a program to Calculate Factorial of N number using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Calculate Factorial of N number.
int recursiveFunction(int n){
    if(n == 1){
        return 1;
    }else if(n == 0){
        return 0;
    }else{
        return (n* recursiveFunction(n- 1));
    }
}

int main(){
    cout<<"Calculate Factorial of N number using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    int factorial= recursiveFunction(n);
    cout<<"The Factorial of "<<n<<"'th number is : "<<factorial;
    
    //getch();
    return(0);
}