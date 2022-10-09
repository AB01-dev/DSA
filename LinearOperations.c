#include <stdio.h>

void arrInsert(int *arr, int n, int position, int value) {
    for (int i = (n-1); i >= position; i--) {
        arr[i] = arr[i-1];
    } arr[(position-1)] = value;
return;
}

int arrDelete(int *arr, int n, int value) {
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
            for (int j = i; j < n; j++) {
                arr[j] = arr[j+1];
            } i--;
        }
    } return count;
}

int arrDeleteAt(int *arr, int n, int position) {
    int check = 0;
    if (position > n + 1)
        return check;
    else
        check++;
        for (int i = position - 1; i < n - 1; i++) {
            arr[i] = arr[i+1];
        } return check;
}

void arrSearch(int *arr, int n, int value) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("%d found at %d position", value, i+1);
            break;
        }
    } if (i == n)
        printf("%d not found in the array",value);
    printf("\n");
    return;
}

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

int main() {

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value of element at %d position: ", i+1);
        scanf("%d", &arr[i]);
    } int (*ptr)[n] = &arr;

    int option = 0;
    
    while (option != 6) {
        printf("\n\nMenu\n1. Insert\n2. Delete\n3. Search\n4. Sort\n5. Traverse\n6. Exit\n\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1: {
                int pos, val;
                printf("Enter the 'Position' you want to insert into and the 'Element' you want to insert: ");
                scanf("%d %d", &pos, &val);
                if (pos > n + 1)
                    printf("\n%d is out of bounds, you can enter only upto %d position", pos, n+1);
                else {
                    n++;
                    arrInsert(*ptr, n, pos, val);
                }
                break;
            } 
            case 2: {
                int sub_option;
                printf("\n1. by value\n2. by position\n\n");
                scanf("%d", &sub_option);
                if (sub_option == 1) {
                    int value;
                    printf("\nEnter the 'Element' you want to 'Delete': ");
                    scanf("%d", &value);
                    int check = arrDelete(*ptr, n, value);
                    if (check == 0)
                        printf("\n%d does not exist in the array", value);
                    else
                        n -= check;
                }
                else if (sub_option == 2) {
                    int position;
                    printf("\nEnter the 'Position' you want to 'Delete' from: ");
                    scanf("%d", &position);
                    int check = arrDeleteAt(*ptr, n, position);
                    if (check == 0)
                        printf("\n%d is out of bounds, only %d elements exist in the array", position, n);
                    else
                        n--;
                }
                break;
            } 
            case 3: {
                int index, value;
                printf("Enter the Element you want to Search: ");
                scanf("%d", &value);
                arrSearch(*ptr, n, value);
                break;
            } 
            case 4: {
                arrSort(*ptr, n);
                break;
            } 
            case 5: {
                arrTraverse(*ptr, n);
                break;
            } 
            case 6: {
                printf("Quiting...\n");
                break;
            }
            default: {
                printf("Invalid selection");
                break;
        }
        }
    } printf("Out of Loop\n");
    

return 0;
}