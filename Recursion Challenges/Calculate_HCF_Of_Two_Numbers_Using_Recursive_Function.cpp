//Write a program to Calculate HCF of two numbers using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Calculate HCF of two numbers.
int recursiveFunction(int n1, int n2){
    return 0;
}

int main(){
    cout<<"Calculate HCF of two numbers using Recursive function in C++ programming\n";
    
    int firstNumber, secondNumber;
    cout<<"Enter first number here : ";
    cin>>firstNumber;
    cout<<"Enter second number here : ";
    cin>>secondNumber;

    int HCF= recursiveFunction(firstNumber, secondNumber);
    cout<<"The HCF of "<<firstNumber<<" and "<<secondNumber<<" is : "<<HCF;
    
    //getch();
    return(0);
}