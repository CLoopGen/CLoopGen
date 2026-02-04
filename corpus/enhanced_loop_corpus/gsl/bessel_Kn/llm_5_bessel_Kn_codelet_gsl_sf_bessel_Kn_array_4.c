#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern double ex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int range = nmax - nmin;
    for (i = 0; i <= range; i++) {
        if (ex != 1.0) {
            result_array[i] *= ex;
        }
    }
}
