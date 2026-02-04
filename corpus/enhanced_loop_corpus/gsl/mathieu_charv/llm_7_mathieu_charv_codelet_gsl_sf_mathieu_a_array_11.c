#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int odd_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (ii = 0; ii < odd_order * odd_order; ii++) {
        temp = zz[ii];       // Introduce RAW: read before write
        zz[ii] = temp + 0.;  // WAW and WAR dependency via 'temp'; loop-carried through scalar
        temp = zz[ii];       // Additional use to strengthen dependency chain
    }
}
