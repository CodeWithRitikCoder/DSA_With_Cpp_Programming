//Code a program to print Second Alphabet pattern in C++ with Ritik.
/*
like this : E
            D D
            C C C
            B B B B
            A A A A A
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Second Alphabet Pattern in C++ programming\n";
    
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= i; j++){
            printf("%c ", (70-i));
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}