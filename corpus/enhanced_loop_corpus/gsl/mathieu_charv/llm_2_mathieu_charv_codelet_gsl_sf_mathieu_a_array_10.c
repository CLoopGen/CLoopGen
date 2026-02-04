#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *dd;
extern double *ee;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    double *zz_base = zz;
    double *ee_base = ee;
    double *dd_base = dd;
    for (ii = 1; ii < even_order - 1; ii++) {
        int offset = ii * even_order;
        *(zz_base + offset + ii - 1) = *(ee_base + ii);
        *(zz_base + offset + ii)     = *(dd_base + ii);
        *(zz_base + offset + ii + 1) = *(ee_base + ii + 1);
    }
}
