//Write a program to Remove all the duplicates from the given String using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;
int count= 1;

//Recusive Funtion to Remove all the duplicates from the given String.
string recursiveFunctionToRemoveAllTheDuplicatesFromString(string str){
    if(str.length() == 0){
        return "";
    }
    char ch= str[0];
    string ans= recursiveFunctionToRemoveAllTheDuplicatesFromString(str.substr(1));

    if(ch == ans[0]){
        return ans;
    }
    return (ch+ ans);
}

int main(){
    cout<<"Remove all the duplicates from the given String using Recursive function in C++ programming\n";
    
    string str; //like this :- "aaabccccdddddefffffghiiiiii"
    cout<<"Enter your string here : ";
    getline(cin, str);

    string removedDuplicateString= recursiveFunctionToRemoveAllTheDuplicatesFromString(str);
    cout<<"Now your string is : "<<removedDuplicateString;
    
    //getch();
    return(0);
}