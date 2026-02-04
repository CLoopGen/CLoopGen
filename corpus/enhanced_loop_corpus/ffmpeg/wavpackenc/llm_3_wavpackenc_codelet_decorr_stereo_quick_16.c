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
// Consecutive reverse traversal of sample history
for (i = 0; i < nb_samples; i++) {
    int32_t sam, tmp;
    // Rotate indices backwards for reverse access pattern
    int prev_idx = (7 - i % 8);
    int curr_idx = (7 - (i + 1) % 8);
    sam = 2 * dpp->samplesA[prev_idx] - dpp->samplesA[curr_idx];
    dpp->samplesA[curr_idx] = dpp->samplesA[prev_idx];
    out_left[i] = tmp = (dpp->samplesA[prev_idx] = in_left[i]) - (((dpp->weightA) * (sam) + 512) >> 10);
    if ((sam) && (tmp)) {
        int32_t s = (int32_t)((sam) ^ (tmp)) >> 31;
        dpp->weightA = ((dpp->delta) ^ s) + ((dpp->weightA) - s);
    }
    
    sam = 2 * dpp->samplesB[prev_idx] - dpp->samplesB[curr_idx];
    dpp->samplesB[curr_idx] = dpp->samplesB[prev_idx];
    out_right[i] = tmp = (dpp->samplesB[prev_idx] = in_right[i]) - (((dpp->weightB) * (sam) + 512) >> 10);
    if ((sam) && (tmp)) {
        int32_t s = (int32_t)((sam) ^ (tmp)) >> 31;
        dpp->weightB = ((dpp->delta) ^ s) + ((dpp->weightB) - s);
    }
}
}
