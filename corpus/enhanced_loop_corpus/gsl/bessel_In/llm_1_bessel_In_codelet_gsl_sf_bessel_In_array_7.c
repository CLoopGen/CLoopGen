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
    for (j = 0; j <= nmax - nmin; j++) {
        for (int inner = 0; inner < 1; inner++) {
            result_array[j] *= eax;
        }
    }
}
