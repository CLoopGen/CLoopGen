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
    for (k = 0; k < 64; k += 4) {
        int rev_k = 63 - (k / 2);
        Wi[k + 0].i = zi[rev_k].i ^ (1U << 31);
        Wi[k + 1].i = zi[k / 2].i;
        Wi[k + 2].i = zi[rev_k - 1].i ^ (1U << 31);
        Wi[k + 3].i = zi[(k / 2) + 1].i;
    }
}
