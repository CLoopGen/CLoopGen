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
    // Variant 1: Consecutive memory access by flattening the 2D index into a 1D sequential walk
    // This changes the access pattern to be more cache-friendly by accessing memory in increasing order
    int total_elements = n1 * n2;
    double *C_ptr = (double *)C;
    for (int idx = 0; idx < total_elements; idx++) {
        int offset = 2 * idx;
        C_ptr[offset]     = 0.;
        C_ptr[offset + 1] = 0.;
    }
}
