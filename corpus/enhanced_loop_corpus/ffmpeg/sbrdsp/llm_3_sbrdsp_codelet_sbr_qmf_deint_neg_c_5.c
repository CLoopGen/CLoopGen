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
    // Variant 2: Strided memory access with increased stride and wrap-around simulation
    for (i = 0; i < 32; i += 2) {
        int base_s = 63 - (i << 2); // Stride of 4 in source
        int base_v = i << 1;        // Stride of 2 in destination
        if (base_s >= 0) {
            vi[base_v].i = si[base_s].i;
            vi[base_v + 1].i = si[base_s - 1].i ^ (1U << 31);
        }
        if (i + 1 < 32 && (base_s - 2) >= 0) {
            vi[base_v + 2].i = si[base_s - 2].i;
            vi[base_v + 3].i = si[base_s - 3].i ^ (1U << 31);
        }
    }
}
