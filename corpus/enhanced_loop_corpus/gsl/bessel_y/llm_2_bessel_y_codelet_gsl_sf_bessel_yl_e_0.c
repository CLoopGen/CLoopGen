#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int l;
extern  double x;
extern double bym;
extern double by;
extern double byp;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *by_array = (double*)alloca((l + 2) * sizeof(double));
    int offset = 1;
    by_array[offset - 1] = bym;
    by_array[offset] = by;
    for (j = 1; j < l; j++) {
        by_array[offset + j] = (2 * j + 1) / x * by_array[offset + j - 1] - by_array[offset + j - 2];
    }
    byp = by_array[offset + l - 1];
    by = by_array[offset + l - 2];
    bym = by_array[offset + l - 3];
}
