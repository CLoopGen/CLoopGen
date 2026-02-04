#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern unsigned int even_order;
extern unsigned int ii;
extern double *tt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 1; ii < even_order; ii++) {
        double idx_sq = (double)(ii * ii);
        tt[3 * ii] = qq + idx_sq;
        tt[3 * ii + 1] = 4 * idx_sq;
        tt[3 * ii + 2] = qq - idx_sq;
        tt[3 * ii + 3] = 6 * idx_sq;
        tt[3 * ii + 4] = qq;
    }
}
