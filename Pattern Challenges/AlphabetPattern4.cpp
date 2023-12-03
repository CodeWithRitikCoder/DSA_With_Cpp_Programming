//Code a program to print Fourth Alphabet pattern in C++ with Ritik.
/*
like this : E
            E D
            E D C
            E D C B
            E D C B A
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Fourth Alphabet Pattern in C++ programming\n";
    
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= i; j++){
            printf("%c ", (70-j));
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}