// bank program to introduce structures
#include <stdio.h>
#define FUNDLEN 50

typedef struct bank {
	char bankName[FUNDLEN];
	int zipCode;
	int bankID;
} Bank;

struct customer {
	Bank bankInfo;
	int customerID;
	double savingsBalance;
	double checkingBalance;
	double annualInterestRate;
};

typedef struct customer myCustomer;

// can use const for these functions because values will not change
double TotalBalance(const myCustomer* acctPtr); // argument is a pointer
double SavingsShare(const myCustomer patron); // argument is a structure
void PrintBankInfo(const Bank bankhere); //argument is a structure
double AnnualInterestRate(const myCustomer* acctPtr);

int main(void)
{
	Bank gtbank = {
		"Georgia Tech Bank",
		30000,
		8810
	};

	myCustomer Anna = {
		gtbank,
		12345,
		2593.53,
		842.15,
		0.2
	};

	printf("Anna's customerID is %d.\n", Anna.customerID);
	printf("Anna has a total of $%.2f.\n", TotalBalance(&Anna));
	printf("%.1f percent of her total is in savings.\n", SavingsShare(Anna));
	printf("Her bank's ID is %d.\n", Anna.bankInfo.bankID);
	printf("Annual interest rate is $%.2f.\n", (Anna.annualInterestRate * TotalBalance(&Anna)));
	printf("Annual interest rate is $%.2f. (By function)\n", AnnualInterestRate(&Anna));
	PrintBankInfo(Anna.bankInfo);

}

double TotalBalance(const myCustomer* acctPtr)
{
	// use -> notation because acct is a pointer; this allows access to the field
	return (acctPtr->savingsBalance + acctPtr->checkingBalance);
}

double SavingsShare(const myCustomer patron) // argument is a structure
{
	return (100.0 * patron.savingsBalance / (patron.savingsBalance + patron.checkingBalance));
}

void PrintBankInfo(const Bank bankhere) //argument is a structure
{
	printf("Her bank's name is %s.\n", bankhere.bankName);
}

double AnnualInterestRate(const myCustomer* acctPtr) {
	return (acctPtr->annualInterestRate * (acctPtr->checkingBalance + acctPtr->savingsBalance));
}