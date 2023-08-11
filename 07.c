#include <stdio.h>

// Function to swap two numbers
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform quicksort
int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to calculate median
double calculateMedian(double arr[], int n) {
    quickSort(arr, 0, n - 1);

    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        return arr[n / 2];
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    double median = calculateMedian(arr, n);

    printf("Median = %.2lf\n", median);

    return 0;
}