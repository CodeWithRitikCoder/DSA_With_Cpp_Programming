//Write a program to Print First N Odd Natural number in Reverse Order using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Print First N Odd natural Number in Reverse Order.
void recursiveFunction(int n){
    if(n == 0){
        return;
    }else{
        cout<<(n* 2)- 1<<endl;
        recursiveFunction(n- 1);
    }
}

int main(){
    cout<<"Print First N Odd Natural number in Reverse Order using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    recursiveFunction(n);
    
    //getch();
    return(0);
}