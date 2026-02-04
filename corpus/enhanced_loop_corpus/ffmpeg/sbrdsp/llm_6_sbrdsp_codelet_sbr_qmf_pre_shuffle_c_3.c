#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union av_intfloat32 {
    uint32_t i;
    float f;
};


extern union av_intfloat32 *zi;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 31; k += 2) {
        uint32_t temp1 = zi[64 - k].i ^ (1U << 31);
        uint32_t temp2 = zi[k + 1].i;
        uint32_t temp3 = zi[63 - k].i ^ (1U << 31);
        uint32_t temp4 = zi[k + 2].i;

        zi[64 + 2 * k + 0].i = temp1;
        zi[64 + 2 * k + 1].i = temp2;
        zi[64 + 2 * k + 2].i = temp3;
        zi[64 + 2 * k + 3].i = temp4;
    }
}
