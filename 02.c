/* WAP to find the sum and aveage of elements of an array */

#include <stdio.h>
int main() {
    int array[100], n, i;
    float sum = 0, average;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }
    average = sum / n;
    printf("The sum of array elements is %.2f\n", sum);
    printf("The average of array elements is %.2f\n", average);
}
