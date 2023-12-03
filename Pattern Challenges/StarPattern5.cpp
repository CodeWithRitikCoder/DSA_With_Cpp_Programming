//Code a program to print Fifth Star pattern in C++ with Ritik.
/*
like this : *
            * *
            * * *
            * * * *
            * * * * *
            * * * *
            * * *
            * *
            * 
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Fifth Star Pattern in C++ programming\n";
    
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i= 1; i<= 4; i++){
        for(int j= 4; j>= i; j--){
            cout<<"* ";
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}