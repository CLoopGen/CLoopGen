#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *weight;
extern int i;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        int idx = i * 8 + j;
        int one = 36;
        int qns = 4;
        int w;
        w = ((weight[idx]) >= 0 ? (weight[idx]) : (-(weight[idx]))) + qns * one;
        w = 15 + (48 * qns * one + w / 2) / w;
        weight[idx] = w;
        ((void)0);
        ((void)0);
        sum += w * w;
    }
}
}
