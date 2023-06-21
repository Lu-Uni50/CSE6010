#include<stdio.h>

int running_sum(int n)
{
	// n: the integer that want to be sum up to
	if (n==1)
		return 1;
	else
		return n + running_sum(n - 1);
}

void running_sum_loop(int n)
{
	int i, sum = 0;
	printf("\n\nFOR loop mode:\n");
	for (i = 1; i <= n; i++){
		sum += i;
		printf("Now turn to %d. The sum is currently %d.\n", i, sum);
	}
}

int running_sum_verify(int n)
{
	return n*(n+1)/2;
}

int main()
{
	int sum_up, N;
	printf("Enter the integer that you wish to running sum to: ");
	scanf("%d", &N);
	sum_up = running_sum(N);
	printf("The running sum to %d is %d", N, sum_up);
	running_sum_loop(N);
	printf("\nVerify: The correct sum should be %d.", running_sum_verify(N));
	return 0;
}