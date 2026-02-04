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
extern int m;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < nb_samples; i++) {
        int32_t sam, tmp;
        // Strided access with step of 2 (mod 8 to stay in bounds)
        int idx_m = (m * 2) & 7;
        int idx_k = (k * 2) & 7;
        sam = dpp->samplesA[idx_m];
        out_left[i] = tmp = (dpp->samplesA[idx_k] = in_left[i]) - (((dpp->weightA) * (sam) + 512) >> 10);
        if (sam && tmp) {
            int32_t s = (int32_t)(sam ^ tmp) >> 31;
            dpp->weightA = (dpp->delta ^ s) + (dpp->weightA - s);
        }
        sam = dpp->samplesB[idx_m];
        out_right[i] = tmp = (dpp->samplesB[idx_k] = in_right[i]) - (((dpp->weightB) * (sam) + 512) >> 10);
        if (sam && tmp) {
            int32_t s = (int32_t)(sam ^ tmp) >> 31;
            dpp->weightB = (dpp->delta ^ s) + (dpp->weightB - s);
        }
        m = (m + 1) & 7;
        k = (k + 1) & 7;
    }
}
