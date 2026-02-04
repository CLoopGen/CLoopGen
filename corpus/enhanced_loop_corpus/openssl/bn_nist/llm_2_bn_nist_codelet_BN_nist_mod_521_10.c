#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int stride = 2;
    for (ii = 0; ii < top - ((521 + (8 * 8) - 1) / (8 * 8) - 1); ii++) {
        if (ii * stride < top) {
            (t_d)[ii] = src[ii * stride];
        }
    }
}
