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



void loop(){
    for (k = 0; k < 64; k += 4) {
        int idx1 = 63 - (k >> 1);
        int idx2 = k >> 1;
        int widx = 2 * k;
        Wi[widx + 0].i = zi[idx1].i ^ (1U << 31);
        Wi[widx + 1].i = zi[idx2].i;
        Wi[widx + 2].i = zi[idx1 - 1].i ^ (1U << 31);
        Wi[widx + 3].i = zi[idx2 + 1].i;
        Wi[widx + 4].i = zi[idx1 - 2].i ^ (1U << 31);
        Wi[widx + 5].i = zi[idx2 + 2].i;
        Wi[widx + 6].i = zi[idx1 - 3].i ^ (1U << 31);
        Wi[widx + 7].i = zi[idx2 + 3].i;
    }
}
