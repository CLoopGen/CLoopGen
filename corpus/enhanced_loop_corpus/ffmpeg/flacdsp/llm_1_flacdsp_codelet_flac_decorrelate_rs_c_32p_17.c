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
if (len > 0) {
    // Reduced effective loop nesting by unrolling the first iteration and then looping from the second
    unsigned int a0 = in[0][0];
    unsigned int b0 = in[1][0];
    (samples[0][0]) = (a0 + b0) << shift;
    (samples[1][0]) = b0 << shift;

    for (i = 1; i < len; i++) {
        unsigned int a = in[0][i];
        unsigned int b = in[1][i];
        (samples[0][i]) = (a + b) << shift;
        (samples[1][i]) = b << shift;
    }
}
}
