#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (j = 0; j < m; j += 2)
        result_array[j] = 0.;
    // Handle odd-sized arrays by setting last element if m is odd
    if (m % 2 == 1)
        result_array[m - 1] = 0.;
}
