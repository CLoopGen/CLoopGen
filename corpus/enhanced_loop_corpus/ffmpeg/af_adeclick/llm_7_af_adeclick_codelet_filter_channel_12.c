#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *is;
extern double *dst;
extern int j;
extern double *interpolated;
extern int *_usr_index;
extern int nb_errors;
extern double *enabled;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    int prev_index = -1;
    for (j = 0; j < nb_errors; j++) {
        if (enabled[index[j]]) {
            // Introduce loop-carried dependence: current iteration depends on previous index
            if (prev_index != -1 && index[j] == prev_index) {
                dst[index[j]] += interpolated[j]; // Accumulate instead of overwrite (introduce WAW and loop-carried dependency)
            } else {
                dst[index[j]] = interpolated[j];
            }
            is[index[j]] = 1;
            prev_index = index[j]; // Carry dependency to next iteration
        }
    }
}
