#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double init_val = 0.0;
    for (j = 0; j < m * 2; j++) {
        int idx = j / 2;
        if (j % 2 == 0) {
            result_array[idx] = init_val;
        } else {
            result_array[idx] += init_val * 2.0;
        }
    }
}
