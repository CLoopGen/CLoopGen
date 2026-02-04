#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 0; j <= nmax; j++) {
        double sum = 0.0;
        for (k = 0; k < 5; k++) {
            sum += 1.0 / (k + 1);
        }
        result_array[j] = sum * 0.1;
    }
}
