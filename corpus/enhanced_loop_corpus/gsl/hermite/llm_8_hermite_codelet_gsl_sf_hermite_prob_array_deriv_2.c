#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < m; j += 2) {
        if (j + 1 < m) {
            result_array[j] = 0.;
            result_array[j + 1] = 0.;
        } else {
            result_array[j] = 0.;
        }
    }
}
