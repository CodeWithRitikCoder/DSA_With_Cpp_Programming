//Code a program to print Fifth Alphabet pattern in C++ with Ritik.
/*
like this : A
            B C
            D E F
            G H I J
            K L M N O
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Fifth Alphabet Pattern in C++ programming\n";
    
    int a= 65;
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= i; j++){
            printf("%c ", a++);
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}