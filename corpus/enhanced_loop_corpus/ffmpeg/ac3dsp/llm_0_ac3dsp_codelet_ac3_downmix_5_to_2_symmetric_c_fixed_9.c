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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            // Process two iterations in a single loop body
            // First iteration (i)
            v0 = (int64_t)samples[0][i] * front_mix + (int64_t)samples[1][i] * center_mix + (int64_t)samples[3][i] * surround_mix;
            v1 = (int64_t)samples[1][i] * center_mix + (int64_t)samples[2][i] * front_mix + (int64_t)samples[4][i] * surround_mix;
            samples[0][i] = (v0 + 2048) >> 12;
            samples[1][i] = (v1 + 2048) >> 12;

            // Second iteration (i+1)
            v0 = (int64_t)samples[0][i+1] * front_mix + (int64_t)samples[1][i+1] * center_mix + (int64_t)samples[3][i+1] * surround_mix;
            v1 = (int64_t)samples[1][i+1] * center_mix + (int64_t)samples[2][i+1] * front_mix + (int64_t)samples[4][i+1] * surround_mix;
            samples[0][i+1] = (v0 + 2048) >> 12;
            samples[1][i+1] = (v1 + 2048) >> 12;
        } else {
            // Handle odd-sized len: process last element
            v0 = (int64_t)samples[0][i] * front_mix + (int64_t)samples[1][i] * center_mix + (int64_t)samples[3][i] * surround_mix;
            v1 = (int64_t)samples[1][i] * center_mix + (int64_t)samples[2][i] * front_mix + (int64_t)samples[4][i] * surround_mix;
            samples[0][i] = (v0 + 2048) >> 12;
            samples[1][i] = (v1 + 2048) >> 12;
        }
    }
}
