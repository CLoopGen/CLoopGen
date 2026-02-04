#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *local_result = result_array;
    int local_mmax = mmax;
    double prev_val = 0.0;
    for (j = 2; j <= local_mmax; j++) {
        prev_val = prev_val + local_result[j-1]; // Introduce RAW dependency on previous iteration
        local_result[j] = prev_val; // WAW hazard introduced: multiple writes to result_array[j] across iterations if not careful
    }
}
