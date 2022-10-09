#include <stdio.h>

void mergeSort(int *arr, int len) {
    int high = 0, low = 0; int mid = (high + low) / 2;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len / 2; j++) {
            
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }   int (*ptr)[n] = &arr;

    mergeSort(*ptr, n);

return 0;
}