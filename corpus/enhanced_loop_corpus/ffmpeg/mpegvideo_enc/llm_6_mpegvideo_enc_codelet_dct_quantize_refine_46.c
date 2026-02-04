#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *weight;
extern int i;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int one = 36;
    int qns = 4;
    int temp_sum = 0;
    for (i = 0; i < 64; i++) {
        int w;
        int abs_weight = (weight[i] >= 0 ? weight[i] : -weight[i]);
        w = abs_weight + qns * one;
        w = 15 + (48 * qns * one + w / 2) / w;
        weight[i] = w;
        temp_sum += w * w;
    }
    sum += temp_sum;
}
