#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;
extern double eax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse array in reverse order)
    for (j = nmax - nmin; j >= 0; j--) {
        result_array[j] *= eax;
    }
}
