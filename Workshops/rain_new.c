/* find yearly total rainfalls, yearly average rainfalls, and monthly average rainfalls
			for several years of rainfall data */

#include<stdio.h>
#define MONTHS 12   // number of months in a yearly
#define YEARS   5   // number of years of data
int main(void)
{
	// initialize rainfall data for 2016-2020
	double rain[YEARS][MONTHS] = 
	{
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};
	int year, month;
	double subtot, total;
	
	// Initialize pointer:
	double *add_rain;
	
	// Transform to 1d array:
	double rain_new[YEARS * MONTHS];
	for (year = 0; year < YEARS; year++)
	{
		for (month=0; month < MONTHS; month++)
		{
			rain_new[year * MONTHS + month] = rain[year][month];
		}
	}
	
	add_rain = rain_new;
	
	printf(" YEAR    RAINFALL   (inches)\n");

	for (year = 0, total = 0; year < YEARS; year++)
	{  // for each year, sum rainfall for each month
		for (month = 0, subtot = 0; month < MONTHS; month++)
		{
			subtot += *(add_rain + year * MONTHS + month);
		}
		printf("%5d %15.1f\n", 2016+year, subtot);
		total += subtot; // total for all years
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total/YEARS);
	printf("MONTHLY AVERAGES: \n\n");
	printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
	printf(" Nov  Dec\n");
	
	for (month = 0; month < MONTHS; month++)
	{  // for each month, sum rainfall over years
		add_rain = rain_new;
		add_rain = add_rain + month;
		for (year = 0, subtot = 0; year < YEARS; year++)
		{
			subtot += *(add_rain + year * MONTHS);			
		}
		printf("%4.1f ", subtot/YEARS);
	}
	printf("\n");
	
	return 0;	
}

