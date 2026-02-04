#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= lmax; j++) {
        if (j > lmax / 2) {
            result_array[j] = 0.;
        } else {
            result_array[j] = 0.;
        }
    }
}
