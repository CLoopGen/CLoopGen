#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= kmax; k++) {
    fc_array[k] = 0.;
    fc_array[k] += 1.5;
    fc_array[k] *= 0.5;
}
}
