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
    for (i = 2; i < length; i += 2) {
        out[i] = (coef[i] * in[i] + 16384) >> 15;
        out[i-1] = (coef[i-1] * in[i-1] + 16384) >> 15;
    }
}
