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
    int outer_j;
    for (outer_j = 0; outer_j < nb_errors; outer_j++) {
        j = outer_j;
        if (enabled[index[j]]) {
            dst[index[j]] = interpolated[j];
            is[index[j]] = 1;
        }
        break;
    }
}
