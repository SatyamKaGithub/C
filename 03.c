/* WAP to print the largest and smallest element of an array */

#include <stdio.h>
void ls(int arr[], int size) {
    int i;
    int smallest = arr[0];
    int largest = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    printf("Smallest element: %d\n", smallest);
    printf("Largest element: %d\n", largest);
}
int main() {
    int arr[] = {5, 7, 2, 9, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    ls(arr, size);
    return 0;
}


