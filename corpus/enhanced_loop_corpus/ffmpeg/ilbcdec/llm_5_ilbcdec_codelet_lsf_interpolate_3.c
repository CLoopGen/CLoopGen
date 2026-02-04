#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *in1;
extern int16_t *in2;
extern int16_t coef;
extern int size;
extern int invcoef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        int16_t temp1 = in1[i];
        int16_t temp2 = in2[i];
        int32_t sum = coef * temp1 + invcoef * temp2;
        if (sum >= 0) {
            out[i] = (sum + 8192) >> 14;
        } else {
            out[i] = (sum - 8192) >> 14;
        }
    }
}
