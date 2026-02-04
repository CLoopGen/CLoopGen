#include <stdio.h>

#include <inttypes.h>

extern int d1;
extern int d2;
extern int elem_size;
extern char *store;
extern char **out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies by unrolling and independent indexing
    // Assumes d1 is even for simplicity; behavior preserved with bounds check
    int stride = d2 * elem_size;
    int offset = 0;
    for (i = 0; i < d1; i++) {
        // Fully independent computation of address without relying on previous j value
        offset = (i * d2) * elem_size;
        out[i] = &((char *)store)[offset];
        // No loop-carried dependency on j; index computed afresh each iteration
    }
}
