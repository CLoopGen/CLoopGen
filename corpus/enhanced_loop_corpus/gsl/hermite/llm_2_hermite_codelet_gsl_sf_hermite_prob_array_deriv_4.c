#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  int nmax;
extern  double x;
extern double *result_array;
extern double p_n0;
extern double p_n1;
extern double p_n;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (reindexing to write in forward sequential order)
    // We shift the base index for result_array to access consecutively starting from offset m+2
    int base_index = m + 2;
    for (j = m + 1; j <= nmax - 1; j++) {
        p_n = (x * p_n1 - j * p_n0) * (j + 1.) / (j - m + 1.);
        p_n0 = p_n1;
        p_n1 = p_n;
        result_array[base_index + (j - (m + 1))] = p_n;
    }
}
