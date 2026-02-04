#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j <= nmax; j++) {
        for (int k = 0; k < 1; k++)
            result_array[j] = 0.;
    }
}
