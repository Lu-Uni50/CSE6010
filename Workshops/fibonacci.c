#include <stdio.h>

#define N  50   // input value

//fibonacci function
int f(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return f(n - 1) + f(n - 2);
}

int main(void)
{
    // recursion
    for (int i = 0; i < N; i++)
    {
        printf("index: %i, i-th fibonacci: %i\n", i, f(i));
    }

    // non-recursion
    int a = 1;
    int b = 1;

    for (int i = 0; i < N;i++)
    {
        if (i == 0)
        {
            printf("index: %i, %i-th fibonacci: %i\n", i, i, a);
            continue;
        }
        int temp = a;
        a = b;
        b = temp + b;
        printf("index: %i, %i-th fibonacci: %i\n", i, i, a);
    }
}

/* ANSWERS
1. My computer starts to slow down at about 30, and overflowed at 46.
This is because for every loop, the recursion calls twice all f(n) which n < index, which is not very effective.

2. Then non-recursive code does not slow down.
This is because it stores the value of two numbers before the i-th number, it does not call all f(n) over and over. 
*/
