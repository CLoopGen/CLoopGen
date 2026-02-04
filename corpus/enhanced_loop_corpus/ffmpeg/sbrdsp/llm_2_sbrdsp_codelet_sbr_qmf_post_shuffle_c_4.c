#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union av_intfloat32 {
    uint32_t i;
    float f;
};


extern  union av_intfloat32 *zi;
extern union av_intfloat32 *Wi;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (k = 0; k < 32; k += 2) {
        int idx_w_base = 2 * k;
        int idx_z1 = 63 - k;
        int idx_z2 = k;
        int idx_z3 = 62 - k;
        int idx_z4 = k + 1;

        Wi[idx_w_base + 0].i = zi[idx_z1].i ^ (1U << 31);
        Wi[idx_w_base + 1].i = zi[idx_z2 + 0].i;
        Wi[idx_w_base + 2].i = zi[idx_z3].i ^ (1U << 31);
        Wi[idx_w_base + 3].i = zi[idx_z2 + 1].i;
    }
}
