#include <stdio.h>

void arrSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    } return;
}

void arrTraverse(int *arr, int n) {
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
    return;
}

void insertionSorted(int *arr, int n) {
    int element;
    scanf("%d", &element);
    int i = n - 1;
    while (element < arr[i] && i >= 0) {
        arr[i+1] = arr[i];
        i--;
    } arr[i+1] = element;
}

int main() {

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value of element at %d position: ", i+1);
        scanf("%d", &arr[i]);
    } int (*ptr)[n] = &arr;
    
    arrTraverse(*ptr, n);
    arrSort(*ptr, n);
    arrTraverse(*ptr, n);
    insertionSorted(*ptr, n);
    n++;
    arrTraverse(*ptr, n);

return 0;
}