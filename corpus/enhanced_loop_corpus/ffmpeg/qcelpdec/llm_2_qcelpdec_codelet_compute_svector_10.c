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
    // Variant 1: Consecutive memory access with precomputed indices and local stride
    tmp_gain = gain[0] * 0.01;
    int idx = cbseed & 127;
    for (i = 0; i < 4; i++) {
        if (i > 0) tmp_gain = gain[i] * 0.01;
        for (j = 0; j < 40; j++) {
            *cdn_vector++ = tmp_gain * qcelp_rate_full_codebook[idx++];
            idx &= 127; // Wrap-around using bitmask instead of modulo for efficiency
        }
        cbseed += 40; // Update global seed state as in original
    }
}
