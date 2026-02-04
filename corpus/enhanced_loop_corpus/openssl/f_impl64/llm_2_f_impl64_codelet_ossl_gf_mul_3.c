#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern  uint64_t *b;
extern uint64_t aa[4];
extern uint64_t bb[4];
extern uint64_t bbb[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential i from 0 to 3, access elements with a stride of 2, then fill in the gaps.
    // We maintain logic equivalence by processing all 4 indices across two phases.

    for (i = 0; i < 2; i++) {
        uint64_t idx1 = i * 2;           // Even indices: 0, 2
        uint64_t idx2 = i * 2 + 1;       // Odd indices: 1, 3

        // Process even index
        aa[idx1] = a[idx1] + a[idx1 + 4];
        bb[idx1] = b[idx1] + b[idx1 + 4];
        bbb[idx1] = bb[idx1] + b[idx1 + 4];

        // Process odd index
        aa[idx2] = a[idx2] + a[idx2 + 4];
        bb[idx2] = b[idx2] + b[idx2 + 4];
        bbb[idx2] = bb[idx2] + b[idx2 + 4];
    }
}
