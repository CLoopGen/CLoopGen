#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern float *out;
extern  float *in1;
extern  float *in2;
extern integer len;
extern int i;
extern float coeff1;
extern float coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i]     = coeff1 * in1[i] + coeff2 * in2[i];
            out[i + 1] = coeff1 * in1[i + 1] + coeff2 * in2[i + 1];
        } else {
            out[i] = coeff1 * in1[i] + coeff2 * in2[i];
        }
    }
}
