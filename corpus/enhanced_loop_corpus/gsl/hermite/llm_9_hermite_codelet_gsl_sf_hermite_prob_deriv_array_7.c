#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern  int n;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    int count = 0;
    for (j = n + 1; j <= mmax; j++) {
        result_array[j] = 0.;
        sum += j;
        count++;
    }
    // Add auxiliary computation to increase arithmetic intensity
    if (count > 0) sum = sum / count;
}
