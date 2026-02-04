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
    for (i = 1; i < 64; i += 8) {
        for (int step = 0; step < 4 && (i + step) < 64; step += 2) {
            xi[i + step + 0].i ^= 1U << 31;
            xi[i + step + 2].i ^= 1U << 31;
        }
    }
}
