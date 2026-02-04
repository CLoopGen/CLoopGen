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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (3*ii, 3*ii+1, 3*ii+2), we rewrite the loop to write consecutive triplets.
    // This improves spatial locality and cache performance.
    double *base = &tt[3];
    for (ii = 1; ii < even_order - 1; ii++) {
        base[0] = qq;
        base[1] = 4 * ii * ii;
        base[2] = qq;
        base += 3; // Move to next triplet
    }
}
