#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern int m;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = m; depth1 <= lmax; depth1++) {
        for (int depth2 = 0; depth2 < 1; depth2++) {
            result_array[depth1 - m] = 0.;
        }
    }
}
