#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *weight;
extern int i;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 4) {
    int one = 36;
    int qns = 4;
    for (int k = 0; k < 4 && (i + k) < 64; k++) {
        int idx = i + k;
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
