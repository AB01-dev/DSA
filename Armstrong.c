#include <stdio.h>
#include <math.h>

int main() {
    
    int n;
    scanf("%d", &n);
    int temp = n;
    int res = 0;

    int len;
    for (len = n; len != 0; ++len) {
        len /= 10;
    }

    while (temp > 0) {
        int last = temp % 10;
        res += pow(last, len);
        temp /= 10;
    }

    if (res == n)
        printf("Armstrong\n");
    else
        printf("Not Armstrong\n");
        
return 0;
}