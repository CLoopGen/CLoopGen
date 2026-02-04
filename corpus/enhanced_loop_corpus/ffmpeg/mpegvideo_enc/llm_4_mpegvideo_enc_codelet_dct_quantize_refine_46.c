#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *weight;
extern int i;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    int one = 36;
    int qns = 4;
    int w;
    int16_t abs_weight = weight[i];
    if (abs_weight < 0) {
        abs_weight = -abs_weight;
    }
    w = abs_weight + qns * one;
    w = 15 + (48 * qns * one + w / 2) / w;
    weight[i] = w;
    sum += w * w;
}
}
