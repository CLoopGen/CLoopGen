#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j <= mmax; j += 2) {
        result_array[j] = 0.;
        if (j + 1 <= mmax) {
            result_array[j + 1] = 0.;
        }
    }
}
