// WAP to find the palindrome number

#include<iostream>
using namespace std;
int main(){
    int num, reverseNum= 0, originalNum, remainder;
    cout << "Enter an Integr : ";
    cin >> num;
    originalNum = num;
    while (num > 0){
    remainder = num % 10;
    reverseNum= reverseNum * 10 + remainder;
    num /=10;
    }
    if (originalNum == reverseNum){
        cout << originalNum << " is a Palindrome Number" << endl;
    } else {
        cout << originalNum << " Not a Palindrome number" << endl;
    }
    return 0;
}