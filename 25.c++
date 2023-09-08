// WAP to subtract number using function call by address

#include<iostream>
using namespace std;
void sN(int* n1, int* n2, int* result) {
    *result = *n1 - *n2;
}
int main() {
    int n1, n2, result;
    cout << "Number 1 : ";
    cin >> n1;
    cout << "Number 2 : ";
    cin >> n2;
    sN(&n1, &n2, &result);
    cout << " Result : " << result << endl;
    return 0;
}
