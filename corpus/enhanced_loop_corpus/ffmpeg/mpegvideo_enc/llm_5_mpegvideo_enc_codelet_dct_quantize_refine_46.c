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
    if (i % 2 == 0) {
        w = ((weight[i]) >= 0 ? weight[i] : -weight[i]) + qns * one;
        w = 15 + (48 * qns * one + w / 2) / w;
        weight[i] = w;
        sum += w * w;
    } else {
        int temp = weight[i] > 0 ? weight[i] : -weight[i];
        w = temp + qns * one;
        w = 16 + (32 * qns * one + w) / (w + 1);
        weight[i] = w;
        sum += w * w;
    }
}
}
