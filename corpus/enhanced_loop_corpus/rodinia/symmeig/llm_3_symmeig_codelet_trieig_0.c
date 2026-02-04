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
for (i = i_min; i < n - 1; i++)
    if (b_ve[i + 1] == 0.) {
        i_max = i + 1;
        break;
    }

}
