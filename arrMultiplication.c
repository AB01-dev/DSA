#include <stdio.h>

int main() {

    int m = 4, n = 4;
    int mat1[4][4] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };
    int x = 4, y = 4;
    int mat2[4][4] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };

    int result[4][4];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < y; j++) {
            result[i][j] = 0;
            for (int k = 0; k < x; k++) {
                result[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", result[i][j]);
        } printf("\n");
    }

return 0;
}