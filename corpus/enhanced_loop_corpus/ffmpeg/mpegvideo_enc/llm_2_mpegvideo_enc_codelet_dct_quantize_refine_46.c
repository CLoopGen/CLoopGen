#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *weight;
extern int i;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 2) {
    int one = 36;
    int qns = 4;
    int w;
    // Strided access: process every second element
    w = ((weight[i]) >= 0 ? (weight[i]) : (-(weight[i]))) + qns * one;
    w = 15 + (48 * qns * one + w / 2) / w;
    weight[i] = w;
    ((void)0);
    ((void)0);
    sum += w * w;
}
}
