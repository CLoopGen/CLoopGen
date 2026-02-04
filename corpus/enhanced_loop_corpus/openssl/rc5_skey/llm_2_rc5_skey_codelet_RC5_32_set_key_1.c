#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int c;
extern int t;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride
    int *array_ii = &ii;
    int *array_jj = &jj;
    int stride = 2; // Simulate strided access
    for (i = 0; i < j; i += stride) {
        if (++array_ii[0] >= t)
            array_ii[0] = 0;
        if (++array_jj[0] >= c)
            array_jj[0] = 0;
    }
}
