#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 1; j <= lmax; j++) {
        double sum = 0.0;
        for (k = 0; k < 5; k++) {
            sum += (double)(k * j) / (j + 1);
        }
        result_array[j] = sum / 5.0;
    }
}
