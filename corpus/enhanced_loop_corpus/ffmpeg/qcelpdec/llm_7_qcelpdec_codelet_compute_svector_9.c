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
    tmp_gain = gain[0] * (1.373681186 / 32768.);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 20; j++) {
            cbseed = 521 * cbseed + 259;
            *cdn_vector++ = tmp_gain * (int16_t)cbseed;
        }
        if (i + 1 < 8) {
            tmp_gain = gain[i + 1] * (1.373681186 / 32768.);
        }
    }
}
