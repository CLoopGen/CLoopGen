#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union av_intfloat32 {
    uint32_t i;
    float f;
};


extern  union av_intfloat32 *si;
extern union av_intfloat32 *vi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with reversed traversal and offset adjustment
    for (i = 0; i < 32; i++) {
        int idx = 31 - i;  // Reverse iteration index
        vi[2 * idx + 0].i = si[2 * idx + 1].i;
        vi[2 * idx + 1].i = si[2 * idx + 0].i ^ (1U << 31);
    }
}
