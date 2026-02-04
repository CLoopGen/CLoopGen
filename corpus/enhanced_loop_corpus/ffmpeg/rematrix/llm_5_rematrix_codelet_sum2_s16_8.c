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
        if (in1[i] == 0 && in2[i] == 0) {
            out[i] = 0;
            continue;
        }
        out[i] = (((coeff1 * in1[i] + coeff2 * in2[i]) + 16384) >> 15);
    }
}
