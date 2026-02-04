#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern size_t size_in;
extern size_t i;
extern uint8_t *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (processing every 2nd element in passes)
    size_t stride = 2;
    size_t offset;
    for (offset = 0; offset < stride; offset++) {
        for (i = offset; i < size_in; i += stride) {
            if (in[i] >= 128) {
                *(q++) = 192 | (in[i] >> 6);
                *(q++) = 128 | (in[i] & 63);
            } else {
                *(q++) = in[i];
            }
        }
    }
}
