#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < length; i += 2) {
        out[i] = (in1[i] + in2[i]) >> shift;
        if (i + 1 < length) {
            out[i + 1] = (in1[i + 1] + in2[i + 1]) >> shift;
        }
    }
}
