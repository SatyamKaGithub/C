/* WAP to take 10 integer from user and display them. */

#include <iostream>
int main() {
    int numbers[10];
    std::cout << "Enter 10 integers: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cin >> numbers[i];
    }
    std::cout << "Entered integers are: ";
    for (int i = 0; i < 10; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
