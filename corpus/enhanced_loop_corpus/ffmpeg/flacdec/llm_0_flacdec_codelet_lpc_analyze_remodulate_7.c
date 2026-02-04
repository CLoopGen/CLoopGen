#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *decoded;
extern  int coeffs[32];
extern int order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = len - 1; i >= order; i--) {
    int64_t p = 0;
    int unroll_factor = 4;
    int remainder = order % unroll_factor;
    for (j = 0; j < remainder; j++)
        p += coeffs[j] * (int64_t)(int32_t)decoded[i - order + j];
    for (; j <= order - unroll_factor; j += unroll_factor) {
        p += coeffs[j] * (int64_t)(int32_t)decoded[i - order + j];
        p += coeffs[j+1] * (int64_t)(int32_t)decoded[i - order + j+1];
        p += coeffs[j+2] * (int64_t)(int32_t)decoded[i - order + j+2];
        p += coeffs[j+3] * (int64_t)(int32_t)decoded[i - order + j+3];
    }
    decoded[i] -= p >> qlevel;
}
}
