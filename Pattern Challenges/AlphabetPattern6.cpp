//Code a program to print Fifth Alphabet pattern in C++ with Ritik.
/*
like this : O
            N M
            L K J
            I H G F
            E D C B A
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Fifth Alphabet Pattern in C++ programming\n";
    
    int a= 'O';
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= i; j++){
            printf("%c ", a--);
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}