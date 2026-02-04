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
for (j = 0; j < nb_errors; j++) {
    if (!enabled[index[j]]) continue;
    dst[index[j]] = interpolated[j];
    is[index[j]] = 1;
}
}
