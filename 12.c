#include <stdio.h>
#include <stdlib.h>

struct Element {
    int row;
    int col;
    int value;
};
int main() {
    int numRows, numCols, numNonZero;

    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numNonZero);

    struct Element *elements = (struct Element *)malloc(numNonZero * sizeof(struct Element));

    printf("Enter the elements in the format: row col value\n");
    for (int i = 0; i < numNonZero; i++) {
        scanf("%d %d %d", &elements[i].row, &elements[i].col, &elements[i].value);
    }
    printf("\nThree-Tuple Representation of Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numNonZero; i++) {
        printf("%d\t%d\t%d\n", elements[i].row, elements[i].col, elements[i].value);
    }
    free(elements);
    return 0;
}