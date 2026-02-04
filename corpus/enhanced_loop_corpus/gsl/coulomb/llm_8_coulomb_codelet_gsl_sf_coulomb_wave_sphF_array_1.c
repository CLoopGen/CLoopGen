#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= kmax; k += 2) {
        if (k + 1 <= kmax) {
            fc_array[k] = 0.;
            fc_array[k + 1] = 0.;
        } else {
            fc_array[k] = 0.;
        }
    }
}
