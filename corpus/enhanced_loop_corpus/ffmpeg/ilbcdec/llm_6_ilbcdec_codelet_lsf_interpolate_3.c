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
    int temp1, temp2;
    for (i = 0; i < size; i++) {
        temp1 = coef * in1[i];
        temp2 = invcoef * in2[i];
        out[i] = (temp1 + temp2 + 8192) >> 14;
    }
}
