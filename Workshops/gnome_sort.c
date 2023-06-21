#include <stdio.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void gnome_sort(int arr[], int n)
{
    int pos = 0;

    while (pos < n) {
        if (pos == 0 || arr[pos] >= arr[pos - 1])
            pos++;
        else {
            swap(&arr[pos], &arr[pos - 1]);
            pos--;
        }
    }
}

int main()
{
    int arr[] = { 10, 7, 3, 15, 22, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nInput Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    gnome_sort(arr, n);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}