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
    // Variant 2: Strided memory access with increased stride
    // Access memory with a larger stride, visiting every 8th element starting from offset 1,
    // and modifying two elements per iteration with a fixed offset pattern.
    for (i = 1; i < 128; i += 8) {
        if (i + 0 < 64) xi[i + 0].i ^= 1U << 31;
        if (i + 2 < 64) xi[i + 2].i ^= 1U << 31;
    }
}
