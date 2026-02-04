#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and accessing elements in a more cache-friendly order
    double *c_ptr = (double *)C;
    for (i = 0; i < n1; i++) {
        int base_offset = 2 * ldc * i;
        for (j = 0; j < n2; j++) {
            int offset = base_offset + 2 * j;
            c_ptr[offset] = 0.;
            c_ptr[offset + 1] = 0.;
        }
    }
}
