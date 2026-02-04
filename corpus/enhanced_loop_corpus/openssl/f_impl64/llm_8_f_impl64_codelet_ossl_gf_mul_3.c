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
    // Variant 1: Increased computational intensity with more arithmetic operations and reduced trip count via unrolling
    for (i = 0; i < 2; i++) {
        aa[i] = a[i] + a[i + 4] + a[i + 8] + a[i] * 2;
        aa[i + 2] = a[i + 2] + a[i + 6] + a[i + 10] + a[i + 2] * 2;
        bb[i] = b[i] + b[i + 4] + b[i + 8] + b[i] * 3;
        bb[i + 2] = b[i + 2] + b[i + 6] + b[i + 10] + b[i + 2] * 3;
        bbb[i] = bb[i] + b[i + 4] + (b[i] >> 1) - (b[i + 8] & 1);
        bbb[i + 2] = bb[i + 2] + b[i + 6] + (b[i + 2] >> 1) - (b[i + 10] & 1);
    }
}
