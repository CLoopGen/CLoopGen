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
    // Variant 1: Strided memory access (stride of 2)
    for (j = 0; j < pred_order; j += 2) {
        sum += coeffs[j] * (unsigned int)decoded[j];
        if (j + 1 < pred_order) {
            sum += coeffs[j + 1] * (unsigned int)decoded[j + 1];
        }
    }
}
