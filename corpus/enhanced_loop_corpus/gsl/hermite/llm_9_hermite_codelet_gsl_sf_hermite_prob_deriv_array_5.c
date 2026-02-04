#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1, temp2;
    for (j = 1; j <= mmax; j++) {
        temp1 = (double)(j % 3);
        temp2 = (double)((j + 1) % 4);
        result_array[j] = temp1 * temp2 - temp1 + temp2;
    }
}
