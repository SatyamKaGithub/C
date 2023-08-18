#include <stdio.h>
#include <stdlib.h>
int** transposeMatrix(int** matrix, int rows, int cols) {
    int** transpose = (int*)malloc(cols *sizeof(int));
    for (int i = 0; i < cols; i++) {
        transpose[i] = (int*)malloc(rows *sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    return transpose;
}
int main() {
    int N, M;
    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);
    // Allocate memory for the original matrix
    int** matrix = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(M * sizeof(int));
    }
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int** transpose = transposeMatrix(matrix, N, M);
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < M; i++) {
        free(transpose[i]);
    }
    free(transpose);
    return 0;
}
