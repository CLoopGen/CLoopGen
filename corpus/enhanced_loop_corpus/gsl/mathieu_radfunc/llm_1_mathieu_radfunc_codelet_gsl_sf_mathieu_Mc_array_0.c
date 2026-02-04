#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double result_array[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int jj, kk;
    for (jj = 0; jj < (nmax - nmin + 1 + 3) / 4; jj++) {
        for (kk = 0; kk < 4 && (jj * 4 + kk) < (nmax - nmin + 1); kk++) {
            ii = jj * 4 + kk;
            result_array[ii] = 0.;
        }
    }
}
