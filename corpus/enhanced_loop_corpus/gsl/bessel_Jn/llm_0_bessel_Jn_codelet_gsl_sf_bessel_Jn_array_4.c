#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = nmax; i >= nmin; i--) {
    for (int j = 0; j < 1; j++) {
        result_array[i - nmin] = 0.;
    }
}
}
