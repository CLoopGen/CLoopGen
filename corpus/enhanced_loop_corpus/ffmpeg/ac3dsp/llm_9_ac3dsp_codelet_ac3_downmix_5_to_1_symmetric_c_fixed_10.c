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
    for (i = 0; i < len; i++) {
        int64_t temp1 = (int64_t)samples[0][i] * front_mix;
        int64_t temp2 = (int64_t)samples[1][i] * center_mix;
        int64_t temp3 = (int64_t)samples[2][i] * front_mix;
        int64_t temp4 = (int64_t)samples[3][i] * surround_mix;
        int64_t temp5 = (int64_t)samples[4][i] * surround_mix;
        int64_t sum = temp1 + temp2 + temp3 + temp4 + temp5;
        samples[0][i] = (sum + 2048) >> 12;
    }
}
