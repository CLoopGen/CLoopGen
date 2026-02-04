#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *coef;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < length; i++) {
        out[i] = (coef[i] * in[i] + 16384) >> 15;
        out[i-1] = (out[i-1] + out[i]) >> 1; // Introduces WAW and RAW loop-carried dependency
    }
    if (length > 0)
        out[length-1] = (out[length-1] + 16384) >> 15; // Fix last element if needed
}
