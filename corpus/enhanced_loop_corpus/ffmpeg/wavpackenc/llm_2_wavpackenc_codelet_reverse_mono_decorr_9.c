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
    // Instead of swapping elements symmetrically from both ends, traverse with a fixed stride
    // Here we use stride of 2, accessing every second element in a circular buffer of size 8
    int stride = 2;
    for (i = 0, j = (dpp->value - 1) % 8, k = 0; k < dpp->value / 2; i = (i + stride) & (8 - 1), j = (j + stride) & (8 - 1), k++) {
        i &= (8 - 1);
        j &= (8 - 1);
        dpp->samplesA[i] ^= dpp->samplesA[j];
        dpp->samplesA[j] ^= dpp->samplesA[i];
        dpp->samplesA[i] ^= dpp->samplesA[j];
    }
}
