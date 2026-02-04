#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int32_t ff_vc1_dqscale[63];
extern int16_t *ac_val2;
extern int q1;
extern int q2;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    for (k = 1; k < 8; k++)
        temp[k] = (int)(ac_val2[k + 8] * (unsigned int)q2 * ff_vc1_dqscale[q1 - 1] + 131072) >> 18;
    for (k = 1; k < 8; k++)
        ac_val2[k + 8] = temp[k];
}
