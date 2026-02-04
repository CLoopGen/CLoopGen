#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1, temp2;
    for (k = 0; k <= kmax; k++) {
        temp1 = (double)(k % 3) * 0.1;
        temp2 = (double)((k + 1) % 4) * 0.05;
        fc_array[k] = temp1 - temp2;
        fc_array[k] *= 2.0;
        fc_array[k] += temp1 + temp2;
    }
}
