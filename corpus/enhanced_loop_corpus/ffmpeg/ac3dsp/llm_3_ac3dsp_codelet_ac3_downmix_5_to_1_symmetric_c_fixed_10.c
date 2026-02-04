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
    // Variant 2: Consecutive Block Access with Pointer Arithmetic
    int32_t *s0 = samples[0];
    int32_t *s1 = samples[1];
    int32_t *s2 = samples[2];
    int32_t *s3 = samples[3];
    int32_t *s4 = samples[4];
    
    for (i = 0; i < len; i++) {
        v0 = (int64_t)s0[i] * front_mix + (int64_t)s1[i] * center_mix + 
             (int64_t)s2[i] * front_mix + (int64_t)s3[i] * surround_mix + 
             (int64_t)s4[i] * surround_mix;
        s0[i] = (v0 + 2048) >> 12;
    }
}
