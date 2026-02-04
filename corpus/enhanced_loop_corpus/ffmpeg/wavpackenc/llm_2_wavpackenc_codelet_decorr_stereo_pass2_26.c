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

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < nb_samples; i += 2) {
        int32_t sam1, tmp1, sam2, tmp2;

        // First sample (left channel)
        sam1 = 2 * dpp->samplesA[0] - dpp->samplesA[1];
        dpp->samplesA[1] = dpp->samplesA[0];
        samples_l[i] = tmp1 = (dpp->samplesA[0] = samples_l[i]) - 
            ((sam1 != (short)sam1) ? 
                (((((sam1 & 65535) * dpp->weightA) >> 9) + (((sam1 & ~65535) >> 9) * dpp->weightA) + 1) >> 1) : 
                (((dpp->weightA * sam1 + 512) >> 10)));

        if (sam1 && tmp1) {
            int32_t s = (int32_t)(sam1 ^ tmp1) >> 31;
            dpp->weightA = (dpp->delta ^ s) + (dpp->weightA - s);
        }

        // Second sample (left channel), if within bounds
        if (i + 1 < nb_samples) {
            sam2 = 2 * dpp->samplesA[0] - dpp->samplesA[1];
            dpp->samplesA[1] = dpp->samplesA[0];
            samples_l[i+1] = tmp2 = (dpp->samplesA[0] = samples_l[i+1]) - 
                ((sam2 != (short)sam2) ? 
                    (((((sam2 & 65535) * dpp->weightA) >> 9) + (((sam2 & ~65535) >> 9) * dpp->weightA) + 1) >> 1) : 
                    (((dpp->weightA * sam2 + 512) >> 10)));

            if (sam2 && tmp2) {
                int32_t s = (int32_t)(sam2 ^ tmp2) >> 31;
                dpp->weightA = (dpp->delta ^ s) + (dpp->weightA - s);
            }
        }

        // Same unrolled logic for right channel
        sam1 = 2 * dpp->samplesB[0] - dpp->samplesB[1];
        dpp->samplesB[1] = dpp->samplesB[0];
        samples_r[i] = tmp1 = (dpp->samplesB[0] = samples_r[i]) - 
            ((sam1 != (short)sam1) ? 
                (((((sam1 & 65535) * dpp->weightB) >> 9) + (((sam1 & ~65535) >> 9) * dpp->weightB) + 1) >> 1) : 
                (((dpp->weightB * sam1 + 512) >> 10)));

        if (sam1 && tmp1) {
            int32_t s = (int32_t)(sam1 ^ tmp1) >> 31;
            dpp->weightB = (dpp->delta ^ s) + (dpp->weightB - s);
        }

        if (i + 1 < nb_samples) {
            sam2 = 2 * dpp->samplesB[0] - dpp->samplesB[1];
            dpp->samplesB[1] = dpp->samplesB[0];
            samples_r[i+1] = tmp2 = (dpp->samplesB[0] = samples_r[i+1]) - 
                ((sam2 != (short)sam2) ? 
                    (((((sam2 & 65535) * dpp->weightB) >> 9) + (((sam2 & ~65535) >> 9) * dpp->weightB) + 1) >> 1) : 
                    (((dpp->weightB * sam2 + 512) >> 10)));

            if (sam2 && tmp2) {
                int32_t s = (int32_t)(sam2 ^ tmp2) >> 31;
                dpp->weightB = (dpp->delta ^ s) + (dpp->weightB - s);
            }
        }
    }
}
