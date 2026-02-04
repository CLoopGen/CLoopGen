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
    for (i = 0; i < length; i++) {
        int16_t product1 = coef[i] * in[i];
        int16_t product2 = (i > 0) ? coef[i-1] * in[i-1] : 0;
        int16_t sum = product1 + product2 + 32768;
        out[i] = (sum) >> 15;
    }
}
