
#include <stdio.h>

int main() {
    int a;
    printf("enter the number: ");
    if (scanf("%d", &a) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (a < 0) {
        printf("enter a number greater than zero\n");
        return 0;
    }

    if (a % 2 == 0) {
        printf("the given number is even\n");
    } else {
        printf("the given number is odd\n");
    }

    return 0;
}