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
    if (length <= 1) return;
    for (i = 1; i < length; i++) {
        int16_t temp = in[i];
        out[i] = (coef[i] * temp + 16384) >> 15;
    }
}
