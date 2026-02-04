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
    for (j = 0; j < pred_order && j < 32; j += 2) {
        int32_t val1 = decoded[j];
        int temp_sum = coeffs[j] * (unsigned int)val1;
        if (j + 1 < pred_order) {
            int32_t val2 = decoded[j + 1];
            temp_sum += coeffs[j + 1] * (unsigned int)val2;
        }
        sum += temp_sum;
    }
}
