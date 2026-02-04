#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (j = 0; j <= (nmax - nmin) / 2; j++) {
    int idx1 = j * step;
    int idx2 = j * step + 1;
    result_array[idx1] = 0.;
    if (idx2 <= nmax - nmin) {
        result_array[idx2] = 0.;
    }
}
}
