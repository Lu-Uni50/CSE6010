#include <stdio.h>
#include <math.h>

int get_num_repete(int i, int m, int n);

int main(void)
{
    // get inputs from user

    // x - minimum range
    printf("Enter minimum of range: ");
    int x;
    scanf("%i", &x);

    //valid x
    if (x < 0)
    {
        printf("x needs to be a positive integer\n");
        return 1;
    }

    // y - maximum range
    printf("Enter maximum of range: ");
    //valid y
    int y;
    scanf("%i", &y);

    //valid y
    if (y < x)
    {
        printf("y has to be larger than x\n");
        return 2;
    }

    // m - specific digit of interest
    printf("Specific digit of interest: ");
    int m;
    scanf("%i", &m);

    //valid m
    if (m < 0 | m > 9)
    {
        printf("m needs to be an integer between 0 - 9");
        return 3;
    }

    // n - the number of repetitions of m
    printf("The number of repetitions of the digit: ");
    int n;
    scanf("%i", &n);

    //valid n
    if (x < 0)
    {
        printf("n needs to be a positive integer\n");
        return 4;
    }

    // compare whether repete
    int count = 0;

    //for each number
    for (int i = x; i <= y; i++)
    {
        int num = get_num_repete(i, m, n);

        count += num;

        //printf("flag1: %i, %i, %i", i, num, count);
    }

    // print out result
    printf("The number of integers from %i to %i that include exactly %i %i is %i.\n", x, y, n, m, count);

    return 0;
}

int get_num_repete(int i, int m, int n)
{
    // count how many m
    int counter = 0;

    while (i)
    {
        if ((i % 10) == m)
        {
            counter++;
        }
        i /= 10;
    }

    if (counter != n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}