#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long numkeys;
extern unsigned long i;
extern unsigned long **lp;
extern unsigned long *lres;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing lp[i][k + 0..3] with fixed offsets, access four consecutive elements starting from k
    for (i = 1; i < numkeys; i++) {
        unsigned long *base = lp[i] + k;
        lres[0] &= base[0];
        lres[1] &= base[1];
        lres[2] &= base[2];
        lres[3] &= base[3];
    }
}
