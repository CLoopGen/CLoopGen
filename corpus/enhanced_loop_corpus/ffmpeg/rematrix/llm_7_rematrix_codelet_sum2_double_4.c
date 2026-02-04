#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern double *out;
extern  double *in1;
extern  double *in2;
extern integer len;
extern int i;
extern double coeff1;
extern double coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i++) {
        out[i] = coeff1 * in1[i-1] + coeff2 * in2[i];
    }
    if (len > 0) {
        out[0] = coeff1 * in1[0] + coeff2 * in2[0];
    }
}
