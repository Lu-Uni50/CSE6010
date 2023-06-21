#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include<stdbool.h>

#define MAXROW 1000

// Represents a row
typedef struct flight
{
    int flnum;
    char* arriv_ap;
    int sch_artime;
    int act_artime;
    int delay_time;
}
flight;

typedef struct airport
{
    char* ap_name;
    int sum_delay;
    int total_f_num;
    int delay_f_num;
    float avg_delay_all;
    float avg_delay_late;
}
airport;

void initialize_flights(flight* flights, int rownum);
int flight_delay(flight f);
void load_flights(char *inputfile, flight* flights, int rownum);
// void print_flights(flight* flightArray, int num);

void initialize_airports(flight* flights, airport* airports, int airportnum);
void load_airports(flight* flights, airport* airports, int airportnum, int rownum);
void print_airports(airport* airports, int num);

void switch_methods(airport* airports, int airportnum, char sort);
void write_txt(airport* airports, int airportnum, char* outputfile);

void insertion_sort(airport* airports, int airportnum);
void swap(airport* a, airport* b);
void heapify(airport* airports, int airportnum, int i);
void heapSort(airport* airports, int airportnum);
void merge(airport* airports, int l, int m, int r);
void mergeSort(airport* airports, int l, int r);