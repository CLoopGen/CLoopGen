#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern int k;
extern int32_t lpc32[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 20; i += 2) {
    int j;
    unsigned int maxabs = 0;
    unsigned int candidate_index[8], candidate_count = 0;
    for (j = 0, k = 0; j < order; j++) {
        unsigned int x = (lpc32[j] >= 0) ? lpc32[j] : (unsigned int)(-lpc32[j]);
        if (x >= maxabs) {
            if (x > maxabs) {
                maxabs = x;
                candidate_count = 0;
            }
            if (candidate_count < 8) {
                candidate_index[candidate_count++] = j;
            }
        }
    }
    maxabs = (maxabs + 48) >> 5;
    if (maxabs > 65535) {
        unsigned int chirp, chirp_base;
        maxabs = (maxabs > 327676) ? 327676 : maxabs;
        chirp_base = chirp = 130940 - ((maxabs - 65535) << 15) / ((maxabs * (candidate_index[0] + 1)) >> 3);
        for (k = 0; k < order; k++) {
            lpc32[k] = (int32_t)(((((int64_t)lpc32[k] * chirp) >> 17) + 1) >> 1);
            chirp = (chirp_base * chirp + 65536) >> 17;
        }
    } else if (maxabs > 32767) {
        for (k = 0; k < order; k++) {
            lpc32[k] = (int32_t)((int64_t)lpc32[k] >> 1);
        }
    }
}
}
