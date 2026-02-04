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
v0 = 0;
v1 = 0;
for (i = 0; i < len; i++) {
    int64_t s0 = samples[0][i];
    int64_t s1 = samples[1][i];
    int64_t s2 = samples[2][i];
    int64_t s3 = samples[3][i];
    int64_t s4 = samples[4][i];

    v0 = s0 * front_mix + s1 * center_mix + s3 * surround_mix;
    samples[0][i] = (v0 + 2048) >> 12;

    v1 = s1 * center_mix + s2 * front_mix + s4 * surround_mix;
    samples[1][i] = (v1 + 2048) >> 12;
}
}
