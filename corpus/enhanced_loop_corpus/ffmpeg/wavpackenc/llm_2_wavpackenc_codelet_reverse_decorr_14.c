#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct Decorr {
    int delta;
    int value;
    int weightA;
    int weightB;
    int samplesA[8];
    int samplesB[8];
    int sumA;
    int sumB;
};


extern struct Decorr *dpp;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of swapping elements symmetrically from both ends, traverse with a fixed stride (e.g., step of 2)
    // and perform swaps between elements offset by a constant distance.
    int stride = 2;
    for (i = 0, k = 0; k < dpp->value / 4; i += stride, k++) {
        int idx1 = (i) & (8 - 1);
        int idx2 = (i + stride) & (8 - 1);
        dpp->samplesA[idx1] ^= dpp->samplesA[idx2];
        dpp->samplesA[idx2] ^= dpp->samplesA[idx1];
        dpp->samplesA[idx1] ^= dpp->samplesA[idx2];
        dpp->samplesB[idx1] ^= dpp->samplesB[idx2];
        dpp->samplesB[idx2] ^= dpp->samplesB[idx1];
        dpp->samplesB[idx1] ^= dpp->samplesB[idx2];
    }
}
