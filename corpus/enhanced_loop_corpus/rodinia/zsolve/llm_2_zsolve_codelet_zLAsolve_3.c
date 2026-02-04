#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern int i;
extern complex *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, traversing backwards)
    for (i = ((dim - 1) | 1); i >= 0; i -= 2) {
        if (!((b_ve[i]).re == 0. && (b_ve[i]).im == 0.))
            break;
        if (i == 1) break; // Prevent underflow when dim is odd
    }
}
