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
for (i = 0; i < nb_samples; i++) {
    int32_t sam, tmp;
    // Strided access with step of 2, wrapping using modulo to stay within bounds
    int idx0 = (2 * i) % 8;
    int idx1 = (2 * i + 1) % 8;
    sam = 2 * dpp->samplesA[idx0] - dpp->samplesA[idx1];
    dpp->samplesA[idx1] = dpp->samplesA[idx0];
    out_left[i] = tmp = (dpp->samplesA[idx0] = in_left[i]) - (((dpp->weightA) * (sam) + 512) >> 10);
    if ((sam) && (tmp)) {
        int32_t s = (int32_t)((sam) ^ (tmp)) >> 31;
        dpp->weightA = ((dpp->delta) ^ s) + ((dpp->weightA) - s);
    }
    
    sam = 2 * dpp->samplesB[idx0] - dpp->samplesB[idx1];
    dpp->samplesB[idx1] = dpp->samplesB[idx0];
    out_right[i] = tmp = (dpp->samplesB[idx0] = in_right[i]) - (((dpp->weightB) * (sam) + 512) >> 10);
    if ((sam) && (tmp)) {
        int32_t s = (int32_t)((sam) ^ (tmp)) >> 31;
        dpp->weightB = ((dpp->delta) ^ s) + ((dpp->weightB) - s);
    }
}
}
