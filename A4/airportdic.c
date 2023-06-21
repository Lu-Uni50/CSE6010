#include "airport.h"

//initialize flights
void initialize_flights(flight* flights, int rownum)
{
    for (int i = 0; i<rownum; i++)
    {
        flights[i].flnum = 0;
        flights[i].arriv_ap = (char *)malloc(4);
        strcpy(flights[i].arriv_ap, "na");
        flights[i].sch_artime = 0;
        flights[i].act_artime = 0;
        flights[i].delay_time = 0;
    }
    printf("successful initialize flights\n");
}



//load input files into memory, returning true if successful, else false
void load_flights(char *inputfile, flight* flights, int rownum)
{
    FILE *input = fopen(inputfile,"r");

    //rows from input file
    char row[MAXROW];
    char* tokens[MAXROW];
    int r = 0;

    while (r<rownum) 
    {
        r++;    
        fgets(row, MAXROW, input);
        // printf("%i: %s\n",i,row);

        if (r == 1)
        {
            r++;
            continue;
        }

        int t = 0;
        tokens[t] = strtok(row, ",");
        while(tokens[t] != NULL)
        {
            tokens[++t] = strtok(NULL, ",");
        }
        
        int i = r-3;
        flights[i].flnum = atoi(tokens[1]);
        strcpy(flights[i].arriv_ap, tokens[3]);
        flights[i].sch_artime = atoi(tokens[6]);
        flights[i].act_artime = atoi(tokens[7]);

        if (flight_delay(flights[i]) <= 0)
        {
            flights[i].delay_time = 0;
        }
        else
        {
            flights[i].delay_time = flight_delay(flights[i]);
        }
    }
    fclose(input);
    printf("successful load\n");
}

// calculate delay time for each flight
int flight_delay(flight f)
{
   int act, act_h, act_m; //actuall arrive time, hour, minutes
   int sch, sch_h, sch_m; //schedule arrvie time, hour, minutes
   int dt; //delay time

    act = f.act_artime;
    sch = f.sch_artime;
    act_m = (((act/10)%10)*10) + (act%10);
    act_h = ((act/(10*10))%10) + (((act/(10*10*10))%10)*10);
    sch_m = (((sch/10)%10)*10) + (sch%10);
    sch_h = ((sch/(10*10))%10) + (((sch/(10*10*10))%10)*10);

    dt = (act_h - sch_h)*60 + (act_m - sch_m);
    if (act>=sch)
    {
        if (dt > 23 * 60)
        {
            dt = (dt - 24*60);
        }
        return dt;
    }
    else
    {
        if (-dt > 120)
        {
            dt = 24*60 - (-dt);
        }
        return dt;
    }
}

// print flights
void print_flights(flight* flights, int num)
{
   int i = 0;
   while(i<num)
   {
        printf("%i, %s, %i, %i, %i\n", flights[i].flnum, flights[i].arriv_ap, flights[i].sch_artime, flights[i].act_artime, flights[i].delay_time);
        i++;
    }
}

// initialize airport array
void initialize_airports(flight* flights, airport* airports, int airportnum)
{
    for (int i = 0; i<airportnum; i++)
    {
        airports[i].ap_name = (char *)malloc(4);
        strcpy(airports[i].ap_name, "na");
        airports[i].sum_delay = 0;
        airports[i].total_f_num = 0;
        airports[i].delay_f_num = 0;
        airports[i].avg_delay_all = 0.0;
        airports[i].avg_delay_late = 0.0;
    }
    printf("successful initialize airports\n");
}

// load airports from flights
void load_airports(flight* flights, airport* airports, int airportnum, int rownum)
{
    for (int j = 0; j<rownum; j++)
    {
        for (int i = 0; i<airportnum; i++)
        {
            //insert flight.airport to empty airport at the first occurence
            //or if it matches with existing airport, then modify index
            if((strcmp(airports[i].ap_name, "na") == 0) || (strcmp(airports[i].ap_name, flights[j].arriv_ap) == 0))
            {
                strcpy(airports[i].ap_name, flights[j].arriv_ap);
                airports[i].total_f_num += 1;
                airports[i].sum_delay += flights[j].delay_time;
                if(flights[j].delay_time > 0)
                {
                    airports[i].delay_f_num += 1;
                }
                airports[i].avg_delay_all = (airports[i].sum_delay)/(airports[i].total_f_num);
                airports[i].avg_delay_late = (airports[i].sum_delay)/(airports[i].delay_f_num);
                // airports[i].avg_delay_late = 10;
                break;
            }  
        }
    }
}

// print airports
void print_airports(airport* airports, int num)
{
   for(int i = 0; i<num; i++)
   {
    printf("%s, %i, %i, %i, %f, %f\n", airports[i].ap_name, airports[i].sum_delay, airports[i].total_f_num, airports[i].delay_f_num, airports[i].avg_delay_all, airports[i].avg_delay_late);
   }
}

//write the results to a txt file
void write_txt(airport* airports, int airportnum, char* outputfile)
{
    FILE *output = fopen(outputfile, "w");
    if (output == NULL)
    {
        printf("can't opening the file %s", outputfile);
        return;
    }
    
    fprintf(output, "Airport Avg Delay-All Avg Delay-Late #Arrivals #Late Arrivals\n");
    for (int i = 0; i < airportnum; i++)
        fprintf(output, " %s %15.3f %15.3f %11d %11d\n",airports[i].ap_name,airports[i].avg_delay_all,airports[i].avg_delay_late,airports[i].total_f_num,airports[i].delay_f_num);
    
    fclose(output);
    printf("successfully write output\n");
    return;
}

// insertion sort
// reference: https://www.geeksforgeeks.org/c-program-for-insertion-sort/
void insertion_sort(airport* airports, int airportnum)
{
    for (int i = 1; i<airportnum; i++)
    {
        airport key = airports[i];
        int j = i - 1;
        while(j >= 0)
        {
            if (((airports[j].avg_delay_all == key.avg_delay_all) && (strcmp(airports[j].ap_name, key.ap_name) > 0)) || (airports[j].avg_delay_all < key.avg_delay_all))
            {
                airports[j + 1] = airports[j];
                j = j - 1;
            }
            else
            {
                break;
            }
        }
        airports[j+1] = key;
    }
}

// swap function
void swap(airport* a, airport* b)
{
    airport temp = *a;
    *a = *b;
    *b = temp;
}

// heap sort - heapify function
// reference: https://www.geeksforgeeks.org/heap-sort/
void heapify(airport* airports, int n, int i)
{
    // Find largest among root, left child and right child
    int smallest = i;
    int l = 2 * i + 1; //left
    int r = 2 * i + 2; //right
  
    if (l < n && airports[l].avg_delay_all < airports[smallest].avg_delay_all || (l < n && airports[l].avg_delay_all == airports[smallest].avg_delay_all) && (strcmp(airports[l].ap_name, airports[smallest].ap_name) > 0))
    {
        smallest = l;
    }
  
    if (r < n && airports[r].avg_delay_all < airports[smallest].avg_delay_all || (r < n && airports[r].avg_delay_all == airports[smallest].avg_delay_all) && (strcmp(airports[r].ap_name, airports[smallest].ap_name) > 0))
    {
        smallest = r;
    }
  
    // Swap and continue heapifying if root is not largest
    if (smallest != i) 
    {
      swap(&airports[i], &airports[smallest]);
      heapify(airports, n, smallest);
    }
}

// heap sort - sort function
void heapSort(airport* airports, int n)
{
    // Build min heap
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(airports, n, i);
    }
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) 
    {
      swap(&airports[0], &airports[i]);
  
      // Heapify root element to get smallest element at root again
      heapify(airports, i, 0);
    }
}

// Merges two subarrays airports[l,m] and airports[m+1..r]
// reference: https://www.geeksforgeeks.org/merge-sort/
void merge(airport* airports, int l, int m, int r) // left, middle and right
{
    int n1 = m - l + 1;
    int n2 = r - m;
    airport L[n1], R[n2]; // create temp arrays
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = airports[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = airports[m + 1 + j];
    }
        
    // merge temp arrays
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].avg_delay_all > R[j].avg_delay_all || L[i].avg_delay_all == R[j].avg_delay_all && (strcmp(L[i].ap_name, R[j].ap_name) < 0)) 
        {
            airports[k] = L[i];
            i++;
        }
        else 
        {
            airports[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any
    while (i < n1) 
    {
        airports[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2) 
    {
        airports[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(airport* airports, int l, int r)
{
    if (l < r) 
    {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(airports, l, m);
        mergeSort(airports, m + 1, r);
        // merge two parts together
        merge(airports, l, m, r);
    }
}

// switch sorting methods
void switch_methods(airport* airports, int airportnum, char sort) 
{
    switch (sort) 
    {
        case 'i':
            insertion_sort(airports, airportnum);
            break;

        case 'h':
            heapSort(airports, airportnum);
            break;

        case 'm':
            mergeSort(airports, 0, (airportnum - 1));
            break;

        default:
            insertion_sort(airports, airportnum);
            break;
    }
}