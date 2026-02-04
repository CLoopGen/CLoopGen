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
    uint32_t prev = 0;
    for (i = 1; i < 64; i += 4) {
        uint32_t current = xi[i + 0].i;
        xi[i + 0].i ^= (1U << 31) ^ prev;
        xi[i + 2].i ^= (1U << 31) ^ xi[i + 0].i;
        prev = current;
    }
}
