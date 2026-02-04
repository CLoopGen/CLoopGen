#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic and local stride
    int32_t *in0 = in[0];
    int32_t *in1 = in[1];
    int16_t *s = samples;
    for (i = 0; i < len; i++) {
        unsigned int a = *(in0 + i);
        unsigned int b = *(in1 + i);
        *(s++) = (a + b) << shift;
        *(s++) = b << shift;
    }
    samples = s; // Update global samples pointer
}
