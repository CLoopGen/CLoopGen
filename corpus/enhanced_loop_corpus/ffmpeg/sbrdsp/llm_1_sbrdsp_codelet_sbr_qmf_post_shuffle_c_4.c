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
    for (int outer = 0; outer < 2; outer++) {
        for (k = outer * 16; k < (outer + 1) * 16 && k < 32; k += 2) {
            Wi[2 * k + 0].i = zi[63 - k].i ^ (1U << 31);
            Wi[2 * k + 1].i = zi[k + 0].i;
            Wi[2 * k + 2].i = zi[62 - k].i ^ (1U << 31);
            Wi[2 * k + 3].i = zi[k + 1].i;
        }
    }
}
