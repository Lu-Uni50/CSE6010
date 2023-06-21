#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int firstValue = 10;
    int secondValue = 20;

    printf("Before swap: first value is: %d, second value is: %d\n", firstValue, secondValue);
    swap(&firstValue, &secondValue);
    printf("After swap: first value is: %d, second value is: %d\n", firstValue, secondValue);
    return 0;
}