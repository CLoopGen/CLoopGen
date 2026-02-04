#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int i_min;
extern int i_max;
extern int n;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = i_min; i < n - 1; i += step)
        if (b_ve[i] == 0.) {
            i_max = i;
            break;
        }
}
