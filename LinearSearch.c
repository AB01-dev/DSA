#include <stdio.h>

int main() {

    int n, i = 0;
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int val;
    scanf("%d", &val);
    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("%d found at position %d\n", val, i+1);
            break;
        }
    } if (i == n)
        printf("Not Found\n");

return 0;
}