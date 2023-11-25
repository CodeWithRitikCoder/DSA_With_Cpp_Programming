//Write a program to Calculate sum of the digits of a given number using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Calculate sum of the digits of a given number.
int recursiveFunction(int n){
    if(n == 1){
        return 1;
    }else if(n == 0){
        return 0;
    }else{
        int remender, quotient;
        remender= n% 10;
        quotient= n/ 10;
        return remender+ recursiveFunction(quotient);

    }
}

int main(){
    cout<<"Calculate sum of the digits of a given number using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    int sum= recursiveFunction(n);
    cout<<"The Sum of the digits of "<<n<<" number is : "<<sum;
    
    //getch();
    return(0);
}