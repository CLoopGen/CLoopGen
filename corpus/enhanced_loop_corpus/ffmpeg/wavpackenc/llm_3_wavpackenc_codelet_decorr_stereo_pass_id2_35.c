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
    // Define a fixed access pattern (indirect indexing) to shuffle array access order
    const int perm[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Interleaved even-odd indices
    for (m = 0, k = dpp->value & (8 - 1), i = 0; i < nb_samples; i++) {
        int32_t sam, tmp;
        int p_m = perm[m & (8 - 1)];
        int p_k = perm[k & (8 - 1)];

        sam = dpp->samplesA[p_m];
        tmp = (dpp->samplesA[p_k] = samples_l[i]) - (((dpp->weightA) * sam + 512) >> 10);
        samples_l[i] = tmp;
        if (sam && tmp)
            dpp->weightA -= (((sam ^ tmp) >> 29) & 4) - 2;

        sam = dpp->samplesB[p_m];
        tmp = (dpp->samplesB[p_k] = samples_r[i]) - (((dpp->weightB) * sam + 512) >> 10);
        samples_r[i] = tmp;
        if (sam && tmp)
            dpp->weightB -= (((sam ^ tmp) >> 29) & 4) - 2;

        m = (m + 1) & (8 - 1);
        k = (k + 1) & (8 - 1);
    }
}
