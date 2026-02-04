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
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing lp[i][k+0], lp[i][k+1], etc., we restructure to access consecutive elements
    // assuming that k is fixed, we traverse the rows with unit stride for better spatial locality
    unsigned long *res0 = &lres[0];
    unsigned long *res1 = &lres[1];
    unsigned long *res2 = &lres[2];
    unsigned long *res3 = &lres[3];
    for (i = 1; i < numkeys; i++) {
        unsigned long *row = lp[i] + k;  // Base pointer shifted to k
        *res0 |= row[0];
        *res1 |= row[1];
        *res2 |= row[2];
        *res3 |= row[3];
    }
}
