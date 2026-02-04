#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **samples;
extern int len;
extern int i;
extern int64_t v0;
extern int16_t front_mix;
extern int16_t center_mix;
extern int16_t surround_mix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp;
    for (i = 0; i < len; i++) {
        temp = (int64_t)samples[0][i] * front_mix + (int64_t)samples[1][i] * center_mix;
        temp += (int64_t)samples[2][i] * front_mix;
        temp += (int64_t)samples[3][i] * surround_mix;
        temp += (int64_t)samples[4][i] * surround_mix;
        samples[0][i] = (temp + 2048) >> 12;
    }
}
