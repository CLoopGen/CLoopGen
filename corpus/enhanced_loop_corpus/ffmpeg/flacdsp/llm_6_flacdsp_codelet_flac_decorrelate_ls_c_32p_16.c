#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    unsigned int a = in[0][i];
    unsigned int b = in[1][i];
    unsigned int diff = a - b;
    // Introduce temporary variables to break direct WAW and RAW dependencies
    // by reordering independent computations.
    int32_t temp1 = a << shift;
    int32_t temp2 = diff << shift;
    samples[0][i] = temp1;
    samples[1][i] = temp2;
}
}
