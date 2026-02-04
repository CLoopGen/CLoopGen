#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern uint8_t *permutation;
extern  uint8_t *scantable;
extern int last;
extern int i;
extern int16_t temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop and duplicated assignments
    // Trip count effectively reduced by factor of 2 via unrolling, but more operations per iteration
    int limit = (last + 1) / 2;
    for (i = 0; i < limit; i++) {
        const int j1 = scantable[2*i];
        const int perm_j1 = permutation[j1];
        block[perm_j1] = temp[j1];

        if (2*i + 1 <= last) {
            const int j2 = scantable[2*i + 1];
            const int perm_j2 = permutation[j2];
            block[perm_j2] = temp[j2];
        }
    }
    // Handle odd-sized last element if needed
    if ((last + 1) % 2 == 1 && last >= 0) {
        const int j = scantable[last];
        const int perm_j = permutation[j];
        block[perm_j] = temp[j];
    }
}
