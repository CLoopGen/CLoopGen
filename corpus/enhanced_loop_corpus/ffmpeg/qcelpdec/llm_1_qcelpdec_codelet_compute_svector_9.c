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
    for (i = 0; i < 160; i++) {
        int idx = i / 20;
        if (i % 20 == 0) {
            tmp_gain = gain[idx] * (1.373681186 / 32768.);
        }
        cbseed = 521 * cbseed + 259;
        *cdn_vector++ = tmp_gain * (int16_t)cbseed;
    }
}
