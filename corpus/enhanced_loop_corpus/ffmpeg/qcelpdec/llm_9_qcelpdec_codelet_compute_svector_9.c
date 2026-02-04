#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *gain;
extern float *cdn_vector;
extern int i;
extern int j;
extern uint16_t cbseed;
extern float tmp_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    tmp_gain = gain[i] * (1.373681186 / 32768.);
    for (j = 0; j < 40; j += 2) {
        cbseed = 521 * cbseed + 259;
        int16_t val = (int16_t)cbseed;
        *cdn_vector++ = tmp_gain * val;
        cbseed = 521 * cbseed + 259;
        val = (int16_t)cbseed;
        *cdn_vector++ = tmp_gain * val * 0.5f;
    }
}
}
