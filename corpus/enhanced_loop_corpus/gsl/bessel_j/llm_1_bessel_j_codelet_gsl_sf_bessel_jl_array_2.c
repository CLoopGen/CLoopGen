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
    int k;
    for (k = 0; k < 1; k++)
        result_array[j] = 0.;
}
}
