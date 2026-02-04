#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *weight;
extern int i;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i += 2) {
    int one = 36;
    int qns = 4;
    int w_lower, w_upper;
    // Unrolled to process two iterations with reduced division usage
    w_lower = ((weight[i]) >= 0 ? weight[i] : -weight[i]) + qns * one;
    w_lower = 15 + (48 * qns * one + w_lower / 2) / w_lower;
    weight[i] = w_lower;
    sum += w_lower * w_lower;

    if (i + 1 < 128) {
        w_upper = ((weight[i+1]) >= 0 ? weight[i+1] : -weight[i+1]) + qns * one;
        w_upper = 15 + (48 * qns * one + w_upper / 2) / w_upper;
        weight[i+1] = w_upper;
        sum += w_upper * w_upper;
    }
}
}
