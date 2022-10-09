#include <stdio.h>

void towerOfHanoi(int n, char source, char destinantion, char helper) {

    if (n == 1) {
        printf("Moved disk 1 from source %c to destination %c\n", source, destinantion);
        return;
    }
    towerOfHanoi(n-1, source, helper, destinantion);
    printf("Moved disk %d from source %c to destination %c\n", n, source, destinantion);
    towerOfHanoi(n-1, helper, destinantion, source);
}
 
int main() {
    
    int n = 5;
    towerOfHanoi(n, 'S', 'D', 'H');
    return 0;
}