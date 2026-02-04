#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t qcelp_rate_full_codebook[128];
extern  float *gain;
extern float *cdn_vector;
extern int i;
extern int j;
extern uint16_t cbseed;
extern float tmp_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmp_gain = gain[0] * 0.01;
    for (i = 0; i < 4; i++) {
        float local_gain = gain[i] * 0.01;
        for (j = 0; j < 40; j++) {
            int idx = cbseed++ & 127;
            *cdn_vector++ = local_gain * qcelp_rate_full_codebook[idx];
        }
        tmp_gain = local_gain; // WAW dependency on tmp_gain, but not loop-carried
    }
}
