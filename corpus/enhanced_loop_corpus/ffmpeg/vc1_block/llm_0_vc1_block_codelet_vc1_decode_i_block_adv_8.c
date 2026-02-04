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
    for (int i = 0; i < 1; i++) {
        for (k = 1; k < 8; k++)
            block[k << sh] += (int)(ac_val[k] * (unsigned int)q2 * ff_vc1_dqscale[q1 - 1] + 131072) >> 18;
    }
}
