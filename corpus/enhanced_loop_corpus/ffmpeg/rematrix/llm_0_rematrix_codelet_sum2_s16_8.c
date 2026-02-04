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
    for (i = 0; i < len; i += 2) {
        out[i] = (((coeff1 * in1[i] + coeff2 * in2[i]) + 16384) >> 15);
        if (i + 1 < len) {
            out[i + 1] = (((coeff1 * in1[i + 1] + coeff2 * in2[i + 1]) + 16384) >> 15);
        }
    }
}
