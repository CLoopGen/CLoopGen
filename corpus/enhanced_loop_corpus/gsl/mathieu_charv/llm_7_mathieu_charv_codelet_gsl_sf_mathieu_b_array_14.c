#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (ii = 0; ii < even_order * even_order; ii++) {
        temp = zz[ii];
        zz[ii] = temp + 0.; // Introduce RAW and WAW dependency via temp
    }
}
