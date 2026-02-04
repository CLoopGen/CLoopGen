#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (k = 0; k <= kmax; k++) {
        temp += 0.;
        fc_array[k] = temp;
    }
}
