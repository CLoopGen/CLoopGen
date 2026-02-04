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
    for (m = 0, k = dpp->value & (8 - 1), i = 0; i < nb_samples; i++) {
        int32_t sam, tmp;
        // Strided read from samplesA with stride of 2 (forward wrapping via modulo-like bitmask)
        int idx_a = (m * 2) & (8 - 1);
        sam = dpp->samplesA[idx_a];
        tmp = (dpp->samplesA[k] = samples_l[i]) - (((dpp->weightA) * sam + 512) >> 10);
        samples_l[i] = tmp;
        if (sam && tmp)
            dpp->weightA -= (((sam ^ tmp) >> 29) & 4) - 2;

        // Strided read from samplesB with stride of 2
        int idx_b = (m * 2) & (8 - 1);
        sam = dpp->samplesB[idx_b];
        tmp = (dpp->samplesB[k] = samples_r[i]) - (((dpp->weightB) * sam + 512) >> 10);
        samples_r[i] = tmp;
        if (sam && tmp)
            dpp->weightB -= (((sam ^ tmp) >> 29) & 4) - 2;

        m = (m + 1) & (8 - 1);
        k = (k + 1) & (8 - 1);
    }
}
