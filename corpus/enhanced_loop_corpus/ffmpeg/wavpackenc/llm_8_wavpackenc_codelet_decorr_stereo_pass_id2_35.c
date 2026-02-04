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
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int nb_samples;
extern int i;
extern int m;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (m = 0, k = dpp->value & 7, i = 0; i < nb_samples; i++) {
        int32_t samA, tmpA, samB, tmpB;
        // Unroll the two similar computation blocks into a single iteration with duplicated logic
        samA = dpp->samplesA[m];
        tmpA = samples_l[i] - (((dpp->weightA * samA) + 512) >> 10);
        dpp->samplesA[k] = samples_l[i];
        samples_l[i] = tmpA;

        samB = dpp->samplesB[m];
        tmpB = samples_r[i] - (((dpp->weightB * samB) + 512) >> 10);
        dpp->samplesB[k] = samples_r[i];
        samples_r[i] = tmpB;

        if (samA && tmpA)
            dpp->weightA -= ((samA ^ tmpA) >> 29) & 4 ? -2 : 2;
        if (samB && tmpB)
            dpp->weightB -= ((samB ^ tmpB) >> 29) & 4 ? -2 : 2;

        m = (m + 1) & 7;
        k = (k + 1) & 7;
    }
}
