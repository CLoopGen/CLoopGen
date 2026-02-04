#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = m; outer <= lmax; outer += 2) {
    result_array[outer - m] = 0.;
    if (outer + 1 <= lmax) {
        result_array[outer + 1 - m] = 0.;
    }
}
}
