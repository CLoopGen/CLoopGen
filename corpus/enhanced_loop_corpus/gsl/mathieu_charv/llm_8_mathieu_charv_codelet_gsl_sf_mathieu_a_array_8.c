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
    for (ii = 2; ii < even_order - 2; ii += 2) {
        tt[3 * ii] = qq * qq;
        tt[3 * ii + 1] = 8 * ii * ii + 4 * ii;
        tt[3 * ii + 2] = qq * qq;
    }
}
