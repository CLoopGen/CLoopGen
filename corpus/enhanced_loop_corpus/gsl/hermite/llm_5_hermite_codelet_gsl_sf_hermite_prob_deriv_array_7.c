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
    for (j = n + 1; j <= mmax; j++) {
        if (j % 2 == 0) {
            result_array[j] = 0.;
        } else {
            result_array[j] = 0.;
        }
    }
}
