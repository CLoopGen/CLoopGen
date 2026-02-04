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
for (i = 0; i < 8; i++) {
    tmp_gain = gain[i] * (1.373681186 / 32768.);
    if (tmp_gain > 0.0f) {
        for (j = 0; j < 20; j++) {
            cbseed = 521 * cbseed + 259;
            *cdn_vector++ = tmp_gain * (int16_t)cbseed;
        }
    }
}
}
