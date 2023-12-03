//Code a program to print Seventh Star pattern in C++ with Ritik.
/*
like this :         *
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
    cout<<"Seventh Star Pattern in C++ programming\n";
    
    for(int i= 0; i< 5; i++){
        for(int j= 1; j<= 5; j++){
            if(j>= 5-i){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= 5; j++){
            if(i>= j){
                cout<<"  ";
            }else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}