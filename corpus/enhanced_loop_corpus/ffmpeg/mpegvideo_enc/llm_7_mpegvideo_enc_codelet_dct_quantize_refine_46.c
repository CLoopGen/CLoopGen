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
    int local_weight[64];
    int temp_sum = 0;

    for (i = 0; i < 64; i++) {
        int w;
        w = ((weight[i]) >= 0 ? weight[i] : (-weight[i])) + qns * one;
        w = 15 + (48 * qns * one + w / 2) / w;
        local_weight[i] = w;
        temp_sum += w * w;
    }

    for (i = 0; i < 64; i++) {
        weight[i] = local_weight[i];
    }

    sum += temp_sum;
}
