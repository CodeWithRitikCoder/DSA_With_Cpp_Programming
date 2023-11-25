//Write a program to Print First N Natural number in Reverse Order using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Print First N natural Number in Reverse Order.
void recursiveFunction(int n){
    if(n == 0){
        return;
    }else{
        cout<<n<<endl;
        recursiveFunction(n- 1);
    }
}

int main(){
    cout<<"Print First N Natural number in Reverse Order using Recursive function in C++ programming\n";
    
    int n;
    cout<<"Enter a number here : ";
    cin>>n;

    recursiveFunction(n);
    
    //getch();
    return(0);
}