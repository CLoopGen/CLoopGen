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
        if (i % 2 == 0) {
            out[i] = (coef * in1[i] + invcoef * in2[i] + 8192) >> 14;
        } else {
            out[i] = (coef * in2[i] + invcoef * in1[i] + 8192) >> 14;
        }
    }
}
