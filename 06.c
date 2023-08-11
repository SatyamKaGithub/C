#include <stdio.h>
#include <math.h>

// Function to calculate the mean
double calculateMean(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the standard deviation
double calculateStandardDeviation(double arr[], int n, double mean) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / n);
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

    double mean = calculateMean(arr, n);
    double standardDeviation = calculateStandardDeviation(arr, n, mean);

    printf("Mean = %.2lf\n", mean);
    printf("Standard Deviation = %.2lf\n", standardDeviation);

    return 0;
}