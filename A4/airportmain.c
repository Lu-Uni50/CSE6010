#include "airport.h"

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 3)
    {
        printf("Usage: ./airportmain [inputfile.csv] [sorting method]\n");
        printf("i - insertion sort \n");
        printf("h - heap sort \n");
        printf("m - merge sort \n");
        return 1;
    }

    FILE *input = fopen(argv[1],"r");
    if (input == NULL)
    {
        printf("Unable to open input file %s.\n", argv[1]);
        return false;
    }
    else{
        printf("successfully open input file %s\n", argv[1]);
    }

    // Read the first row and get the number of flights
    int airportnum;
    int rownum = 0;

    while (feof(input) != true)
    {
        if (rownum == 0)
        {
            fscanf(input,"%d", &airportnum);
            rownum++;
            break;
        }
    }

    for (char c = getc(input); c != EOF; c = getc(input))
    {
        if (c == '\n')
        {
            rownum++;
        }
    }
    // load csv in flights array
    flight* flights = (flight*) malloc(rownum*sizeof(flight));
    initialize_flights(flights, rownum);
    load_flights(argv[1], flights, rownum);

    // load flights data in airports array and calculate delay
    airport* airports = (airport*) malloc(airportnum*sizeof(airport));
    initialize_airports(flights, airports, airportnum);
    load_airports(flights, airports, airportnum, rownum);

    // sort airports with different methods
    switch_methods(airports, airportnum, *argv[2]);

    // print results
    printf("airports after sorting:\n");
    print_airports(airports, 30);
    
    // free memory
    free(flights);
    free(airports);

    //write outputs to txt
    write_txt(airports, airportnum, "output_sorted.txt");

    // Close files
    fclose(input);
}
