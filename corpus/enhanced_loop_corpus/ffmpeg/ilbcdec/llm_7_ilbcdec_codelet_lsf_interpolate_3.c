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
    int offset = 0;
    while (offset < size) {
        out[offset] = (coef * in1[offset] + invcoef * in2[offset] + 8192) >> 14;
        offset++;
    }
}
