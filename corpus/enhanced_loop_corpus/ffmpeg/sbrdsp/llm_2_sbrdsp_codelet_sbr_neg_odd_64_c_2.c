#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union av_intfloat32 {
    uint32_t i;
    float f;
};


extern union av_intfloat32 *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing elements at i+0 and i+2 with step 4 in the original loop,
    // we now traverse consecutive indices and apply the XOR operation to even offsets.
    for (i = 0; i < 64; i += 2) {
        xi[i].i ^= 1U << 31;
        xi[i + 1].i ^= 1U << 31;
    }
}
