//Write a program to Calculate Sum of Square of first N Even Natural number using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Calculate Sum of Square of first N Even Natural number.
int recursiveFunction(int n){
    if(n == 0){
        return 0;
    }else{
        int temp= (n* 2);
        return ((temp* temp)+ recursiveFunction(n- 1 ));
    }
}

int main(){
    cout<<"Calculate Sum of Square of first N Even Natural number using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    int sum= recursiveFunction(n);
    cout<<"The sum of Square of Even Numbers till the "<<n<<"'th number : "<<sum;
    
    //getch();
    return(0);
}