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
    int temp1, temp2;
    for (i = 0; i < len; i++) {
        temp1 = coeff1 * in1[i];
        temp2 = coeff2 * in2[i];
        out[i] = ((temp1 + temp2 + 16384) >> 15);
    }
}
