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
    double temp_val;
    for (ii = 1; ii < even_order - 1; ii++) {
        temp_val = 4 * ii * ii;
        tt[3 * ii] = qq;
        tt[3 * ii + 1] = temp_val;
        tt[3 * ii + 2] = qq;
    }
}
