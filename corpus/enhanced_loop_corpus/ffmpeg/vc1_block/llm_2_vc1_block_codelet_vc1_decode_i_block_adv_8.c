#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int32_t ff_vc1_dqscale[63];
extern int16_t block[64];
extern int16_t *ac_val;
extern int q1;
extern int q2;
extern int k;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access (unrolled with sequential indices)
    int base = 1 << sh;
    for (k = 0; k < 7; k++) {
        int idx = base + (k << sh); // generates strided but consecutive in transformed index space
        block[idx] += (int)(ac_val[k + 1] * (unsigned int)q2 * ff_vc1_dqscale[q1 - 1] + 131072) >> 18;
    }
}
