#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern  int coeffs[32];
extern int pred_order;
extern int j;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    int unroll_factor = 4;
    int limit = pred_order - (pred_order % unroll_factor);
    for (j = 0; j < limit; j += unroll_factor) {
        sum += coeffs[j] * (unsigned int)decoded[j];
        sum += coeffs[j+1] * (unsigned int)decoded[j+1];
        sum += coeffs[j+2] * (unsigned int)decoded[j+2];
        sum += coeffs[j+3] * (unsigned int)decoded[j+3];
    }
    for (; j < pred_order; j++) {
        sum += coeffs[j] * (unsigned int)decoded[j];
    }
}
