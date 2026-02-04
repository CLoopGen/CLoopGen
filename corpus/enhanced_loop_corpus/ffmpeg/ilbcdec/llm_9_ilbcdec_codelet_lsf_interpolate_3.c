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
    int j;
    for (i = 0; i < size; i++) {
        int16_t temp1 = in1[i] >> 2;
        int16_t temp2 = in2[i] >> 2;
        out[i] = (coef * temp1 + invcoef * temp2 + 2048) >> 12;
        for (j = 0; j < 3; j++) {
            temp1 = (temp1 + temp2) >> 1;
            temp2 = (temp2 * coef + 8192) >> 14;
        }
        out[i] ^= temp2;
    }
}
