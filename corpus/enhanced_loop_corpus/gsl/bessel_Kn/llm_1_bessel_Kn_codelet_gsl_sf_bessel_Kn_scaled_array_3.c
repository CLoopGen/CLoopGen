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
    int outer = (nmax - nmin) / 100 + 1;
    int chunk, start, end;
    for (int k = 0; k < outer; k++) {
        start = k * 100;
        end = (start + 100 <= nmax - nmin) ? start + 100 : nmax - nmin + 1;
        if (start > nmax - nmin) break;
        for (j = start; j < end; j++)
            result_array[j] = 0.;
    }
}
