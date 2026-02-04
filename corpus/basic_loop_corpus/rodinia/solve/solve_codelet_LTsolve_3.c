#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = dim - 1; i >= 0; i--)
    if (b_ve[i] != 0.)
        break;

}
