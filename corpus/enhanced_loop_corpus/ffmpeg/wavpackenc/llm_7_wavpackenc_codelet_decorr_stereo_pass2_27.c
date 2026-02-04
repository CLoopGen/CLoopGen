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
        // Unroll loop by factor of 2 to reduce loop-carried dependencies and expose parallelism
        int32_t samA0, tmpA0, samB0, tmpB0;
        int32_t samA1 = 0, tmpA1 = 0, samB1 = 0, tmpB1 = 0;
        int32_t nextA0, nextB0, nextA1, nextB1;

        nextA0 = samples_l[i];
        nextB0 = samples_r[i];

        // First iteration: compute prediction using current model state
        samA0 = dpp->samplesA[0] + ((dpp->samplesA[0] - dpp->samplesA[1]) >> 1);
        samB0 = dpp->samplesB[0] + ((dpp->samplesB[0] - dpp->samplesB[1]) >> 1);

        // Save old values before updating history
        int32_t prevA0 = dpp->samplesA[0], prevB0 = dpp->samplesB[0];
        dpp->samplesA[1] = prevA0;
        dpp->samplesB[1] = prevB0;

        // Apply decorrelation with clamping logic
        tmpA0 = nextA0 - (
            (samA0 != (short)samA0) ?
                (((((samA0 & 65535) * dpp->weightA) >> 9) + (((samA0 & ~65535) >> 9) * dpp->weightA) + 1) >> 1) :
                (((dpp->weightA * samA0 + 512) >> 10))
        );
        tmpB0 = nextB0 - (
            (samB0 != (short)samB0) ?
                (((((samB0 & 65535) * dpp->weightB) >> 9) + (((samB0 & ~65535) >> 9) * dpp->weightB) + 1) >> 1) :
                (((dpp->weightB * samB0 + 512) >> 10))
        );

        // Update current samples
        dpp->samplesA[0] = nextA0;
        dpp->samplesB[0] = nextB0;
        samples_l[i] = tmpA0;
        samples_r[i] = tmpB0;

        // Conditionally update weights based on sign agreement
        if (samA0 && tmpA0) {
            int32_t s = (int32_t)(samA0 ^ tmpA0) >> 31;
            dpp->weightA = (dpp->delta ^ s) + (dpp->weightA - s);
        }
        if (samB0 && tmpB0) {
            int32_t s = (int32_t)(samB0 ^ tmpB0) >> 31;
            dpp->weightB = (dpp->delta ^ s) + (dpp->weightB - s);
        }

        // Second iteration only if within bounds
        if (i + 1 < nb_samples) {
            nextA1 = samples_l[i + 1];
            nextB1 = samples_r[i + 1];

            // Use updated model parameters (including possibly modified weights)
            samA1 = dpp->samplesA[0] + ((dpp->samplesA[0] - dpp->samplesA[1]) >> 1);
            samB1 = dpp->samplesB[0] + ((dpp->samplesB[0] - dpp->samplesB[1]) >> 1);

            int32_t prevA1 = dpp->samplesA[0], prevB1 = dpp->samplesB[0];
            dpp->samplesA[1] = prevA1;
            dpp->samplesB[1] = prevB1;

            tmpA1 = nextA1 - (
                (samA1 != (short)samA1) ?
                    (((((samA1 & 65535) * dpp->weightA) >> 9) + (((samA1 & ~65535) >> 9) * dpp->weightA) + 1) >> 1) :
                    (((dpp->weightA * samA1 + 512) >> 10))
            );
            tmpB1 = nextB1 - (
                (samB1 != (short)samB1) ?
                    (((((samB1 & 65535) * dpp->weightB) >> 9) + (((samB1 & ~65535) >> 9) * dpp->weightB) + 1) >> 1) :
                    (((dpp->weightB * samB1 + 512) >> 10))
            );

            dpp->samplesA[0] = nextA1;
            dpp->samplesB[0] = nextB1;
            samples_l[i + 1] = tmpA1;
            samples_r[i + 1] = tmpB1;

            if (samA1 && tmpA1) {
                int32_t s = (int32_t)(samA1 ^ tmpA1) >> 31;
                dpp->weightA = (dpp->delta ^ s) + (dpp->weightA - s);
            }
            if (samB1 && tmpB1) {
                int32_t s = (int32_t)(samB1 ^ tmpB1) >> 31;
                dpp->weightB = (dpp->delta ^ s) + (dpp->weightB - s);
            }
        }
    }
}
