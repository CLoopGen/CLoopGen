#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in1;
extern  uint8_t *in2;
extern uint8_t *out;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in a forward pass, then handles remainder if n is odd
    int stride = 2;
    int limit = (n / stride) * stride;

    for (i = 0; i < limit; i += stride) {
        out[i] = in1[i] ^ in2[i];
    }
    // Handle leftover element if n is not divisible by stride
    if (limit < n) {
        out[limit] = in1[limit] ^ in2[limit];
    }
}
