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
    if (len > 0) {
        i = 0;
        for (int block = 0; block < len; block += 1) { // Same effective depth but logically grouped as block-like iterations
            v0 = (int64_t)samples[0][i] * front_mix + (int64_t)samples[1][i] * center_mix + 
                 (int64_t)samples[2][i] * front_mix + (int64_t)samples[3][i] * surround_mix + 
                 (int64_t)samples[4][i] * surround_mix;
            samples[0][i] = (v0 + 2048) >> 12;
            i++;
        }
    }
}
