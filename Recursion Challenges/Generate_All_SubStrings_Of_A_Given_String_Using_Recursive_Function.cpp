//Write a program to Generate all subStrings of a given String using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;
int count= 1;

//Recusive Funtion to Generate all subStrings of a given String.
void recursiveFunctionToGenerateAllTheSubString(string str, string answer){
    if(str.length() == 0){
        cout<<answer<<endl;
        return;
    }

    char ch= str[0];
    string ros= str.substr(1);
    recursiveFunctionToGenerateAllTheSubString(ros, answer);
    recursiveFunctionToGenerateAllTheSubString(ros, answer+ ch);
}

int main(){
    cout<<"Generate all subStrings of a given String using Recursive function in C++ programming\n";
    
    string str; //like this :- "ABC", "ABCD" and so on...
    cout<<"Enter your string here : ";
    getline(cin, str);

    recursiveFunctionToGenerateAllTheSubString(str, "");
    
    //getch();
    return(0);
}