#include <stdio.h>

int main() {

    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    int nonZeros = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0)
                nonZeros++;
        }
    }

    int result[3][nonZeros];
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                result[0][k] = i;
                result[1][k] = j;
                result[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZeros; j++) {
            printf("%d ", result[i][j]);
        } printf("\n");
    }

return 0;
}