//Write a program to Replace pi with 3.14 in string using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Replace pi with 3.14 in string.
void recursiveFunction(string str){
    if(str.length()== 0){ // Base case.
        return;
    }
    if((str[0] == 'p') && (str[1] == 'i')){
        cout<<"3.14";
        recursiveFunction(str.substr(2));
    }else{
        cout<<str[0];
        recursiveFunction(str.substr(1));
    }
}

int main(){
    cout<<"Replace pi with 3.14 in string using Recursive function in C++ programming\n";
    
    string str= "pipppiiiipi";
    // cout<<"Enter a string here : ";
    // getline(cin, str); //This line is used to read string with white space.

    recursiveFunction(str);
    
    //getch();
    return(0);
}