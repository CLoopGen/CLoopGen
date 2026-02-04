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


extern int32_t *in_left;
extern int32_t *in_right;
extern int32_t *out_left;
extern int32_t *out_right;
extern int nb_samples;
extern struct Decorr *dpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use reversed sequential access in a circular buffer manner: process samples from end to start with fixed stride
for (i = 0; i < nb_samples; i++) {
    int32_t sam, tmp;
    int rev_idx = 7 - (i % 8); // Reverse the index within the 8-element array

    sam = dpp->samplesA[rev_idx];
    dpp->samplesA[rev_idx] = dpp->samplesA[(rev_idx + 7) % 8]; // Move backward in the buffer
    out_left[i] = tmp = (dpp->samplesA[(rev_idx + 7) % 8] = in_left[i]) - (((dpp->weightA) * (sam) + 512) >> 10);
    if ((sam) && (tmp)) {
        int32_t s = (int32_t)((sam) ^ (tmp)) >> 31;
        dpp->weightA = ((dpp->delta) ^ s) + ((dpp->weightA) - s);
    }

    sam = dpp->samplesB[rev_idx];
    dpp->samplesB[rev_idx] = dpp->samplesB[(rev_idx + 7) % 8];
    out_right[i] = tmp = (dpp->samplesB[(rev_idx + 7) % 8] = in_right[i]) - (((dpp->weightB) * (sam) + 512) >> 10);
    if ((sam) && (tmp)) {
        int32_t s = (int32_t)((sam) ^ (tmp)) >> 31;
        dpp->weightB = ((dpp->delta) ^ s) + ((dpp->weightB) - s);
    }
}
}
