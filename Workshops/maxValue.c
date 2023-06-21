#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define N 5
double returnValue(double array[N], int * idx);
int returnIdx(double array[N], double* value);
void maxValue_Index(double array[N], double* value, int* idx);



int main(){

    double array[5] = {2,8,4,3,6};
    int idx = 0;
    double maxvalue = returnValue(array, &idx);
    printf("Use the maximum value as the return value: \n Max value: %f, Index of max value: %d \n", maxvalue, idx);

    double value = - DBL_MAX;
    int index = returnIdx(array, &value);
    printf("Use the index as the return value: \n Max value: %f, Index of max value: %d \n", value, index);
    
    int idx3 = 0;
    double value3 = - DBL_MAX;
    maxValue_Index(array, &value3, &idx3);
    printf("Use the either as the return value: \n Max value: %f, Index of max value: %d \n", value3, index);


    return 0;

}
double returnValue(double array[N], int* idx){
    double value = - DBL_MAX;
    for (int i = 0; i < N; i++){
        if (value < array[i]){
            value = array[i];
            *idx = i;
        }
    }
    return value;
}

int returnIdx(double array[N], double* value){
    int idx = 0;
    for (int i = 0; i < N; i++){
        if (*value < array[i]){
            *value = array[i];
            idx = i;
        }
    }
    return idx;
}

void maxValue_Index(double array[N], double* value, int * idx){

    for (int i = 0; i < N; i++){
        if (*value < array[i]){
            *value = array[i];
            *idx = i;
        }
    }
}