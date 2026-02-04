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
    // Variant 1: Strided Memory Access (access every 2nd element in reverse order)
    for (i = (len % 2 == 0 ? len - 2 : len - 1); i >= 0; i -= 2) {
        v0 = (int64_t)samples[0][i] * front_mix + (int64_t)samples[1][i] * center_mix + 
             (int64_t)samples[2][i] * front_mix + (int64_t)samples[3][i] * surround_mix + 
             (int64_t)samples[4][i] * surround_mix;
        samples[0][i] = (v0 + 2048) >> 12;
    }
    // Handle odd-length case by processing index 1 if needed
    if (len > 1 && ((len % 2) == 0)) {
        i = 1;
        v0 = (int64_t)samples[0][i] * front_mix + (int64_t)samples[1][i] * center_mix + 
             (int64_t)samples[2][i] * front_mix + (int64_t)samples[3][i] * surround_mix + 
             (int64_t)samples[4][i] * surround_mix;
        samples[0][i] = (v0 + 2048) >> 12;
    }
}
