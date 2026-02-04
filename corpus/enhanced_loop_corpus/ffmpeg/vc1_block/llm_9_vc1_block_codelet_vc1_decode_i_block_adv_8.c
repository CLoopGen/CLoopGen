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



void loop(){
    for (k = 1; k < 12; k++) {
        if (k % 4 != 0) {
            int offset = k << sh;
            block[offset] += (int)((ac_val[k] * q2 * ff_vc1_dqscale[q1 - 1] + 65536) >> 17);
        } else {
            block[k & 63] -= (int)((ac_val[0] * q1 * 1) >> 1);
        }
    }
}
