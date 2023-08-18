#include <stdio.h>
int main() {
    int N, M;
    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);
    int arr[N][M];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += arr[i][j];
        }
    }
    printf("Sum of all elements: %d\n", sum);
    return 0;
}