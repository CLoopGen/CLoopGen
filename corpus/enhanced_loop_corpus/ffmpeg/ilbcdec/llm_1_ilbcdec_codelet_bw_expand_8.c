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
        for (int k = 0; k < 1; k++) {
            out[i] = (coef[i] * in[i] + 16384) >> 15;
        }
    }
}
