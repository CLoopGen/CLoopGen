#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **samples;
extern int len;
extern int i;
extern int64_t v0;
extern int64_t v1;
extern int16_t front_mix;
extern int16_t center_mix;
extern int16_t surround_mix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < len; i++) {
    v0 = (int64_t)samples[0][i] * front_mix;
    v0 += (int64_t)samples[1][i] * center_mix;
    v0 += (int64_t)samples[3][i] * surround_mix;
    v1 = (int64_t)samples[1][i] * center_mix;
    v1 += (int64_t)samples[2][i] * front_mix;
    v1 += (int64_t)samples[4][i] * surround_mix;

    int32_t result0 = (v0 + 2048) >> 12;
    int32_t result1 = (v1 + 2048) >> 12;

    for (j = 0; j < 2; j++) {
        if (j == 0) {
            samples[0][i] = result0;
        } else {
            samples[1][i] = result1;
        }
    }
}
}
