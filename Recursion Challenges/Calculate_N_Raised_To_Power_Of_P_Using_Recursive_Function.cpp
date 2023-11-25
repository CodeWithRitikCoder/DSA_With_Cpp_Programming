//Write a program to Calculate N raised to power of P using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
#include"string.h"
using namespace std;

//Recusive Funtion to Calculate N raised to power of P.
int recursiveFunction(int n, int p){
    if(p == 0){
        return 1;
    }
    int previousPower= recursiveFunction(n, p- 1);
    return (n* previousPower);
}

int main(){
    cout<<"Calculate N raised to power of P using Recursive function in C++ programming\n";
    
    int n, p;
    cout<<"Enter a number here : ";
    cin>>n;
    cout<<"Enter power of "<<n<<" : ";
    cin>>p;

    int nRaisedToPowerP= recursiveFunction(n, p);
    cout<<"The "<<n<<" raised to power "<<p<<" is : "<<nRaisedToPowerP;
    
    //getch();
    return(0);
}