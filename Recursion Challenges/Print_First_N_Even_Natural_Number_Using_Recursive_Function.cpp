//Write a program to Print First N Even Natural number using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Print First N Even natural Number.
void recursiveFunction(int n){
    if(n == 0){
        return;
    }else{
        recursiveFunction(n- 1);
        cout<<(n*2)<<endl;
    }
}

int main(){
    cout<<"Print First N Even Natural number using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    recursiveFunction(n);
    
    //getch();
    return(0);
}