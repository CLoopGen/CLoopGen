#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 1; j <= mmax; j++) {
        double sum = 0.0;
        for (k = 0; k < 5; k++) {
            sum += (double)(k + 1) * 0.1;
        }
        result_array[j] = sum / 5.0;
    }
}
