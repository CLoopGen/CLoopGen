#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern integer len;
extern int i;
extern int coeff1;
extern int coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        int temp = coeff1 * in1[i] + coeff2 * in2[i];
        if (temp > 0)
            out[i] = (temp + 16384) >> 15;
        else
            out[i] = (temp - 16384) >> 15;
    }
}
