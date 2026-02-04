#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double x;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (kmax < 0) return;
    for (k = 0; k <= kmax; k++) {
        fc_array[k] = fc_array[k] / x;
    }
}
