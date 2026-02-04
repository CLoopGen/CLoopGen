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
    // Variant 1: Consecutive memory access with unrolled stride-1 pattern
    // Reorganize access to promote spatial locality by accessing consecutive elements in lp[i]
    for (i = 1; i < numkeys; i++) {
        unsigned long *row = lp[i] + k;
        lres[0] ^= row[0];
        lres[1] ^= row[1];
        lres[2] ^= row[2];
        lres[3] ^= row[3];
    }
}
