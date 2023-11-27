//Write a program to Print Fibonacci series till the Nth Term using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Print Fibonacci series till the Nth Term.
int recursiveFunction(int n){
    if(n == 0 || n == 1){ 
        return n; 
    }else{ 
        return recursiveFunction(n-2) + recursiveFunction(n-1); 
    } 
}

int main(){
    cout<<"Print Fibonacci series till the Nth Term using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;
      for(int i = 0; i< n; i++) { 
        cout << recursiveFunction(i)<< " "; 
    }
    
    //getch();
    return(0);
}