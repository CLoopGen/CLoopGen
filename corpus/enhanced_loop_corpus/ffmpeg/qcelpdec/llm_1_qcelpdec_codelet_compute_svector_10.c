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
    for (i = 0; i < 4; i++) {
        tmp_gain = gain[i] * 0.01;
        for (j = 0; j < 5; j++) {
            for (int k = 0; k < 8; k++) {
                *cdn_vector++ = tmp_gain * qcelp_rate_full_codebook[cbseed++ & 127];
            }
        }
    }
}
