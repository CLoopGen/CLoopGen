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



void loop(){
    for (i = 0; i < 16; i++) {
        uint32_t temp1 = si[63 - 2*i].i;
        uint32_t temp2 = si[63 - 2*i - 1].i ^ (1U << 31);
        uint32_t temp3 = si[63 - 2*i - 2].i;
        uint32_t temp4 = si[63 - 2*i - 3].i ^ (1U << 31);

        vi[i*2].i     = temp1;
        vi[63 - i*2].i   = temp2;
        vi[i*2 + 1].i   = temp3;
        vi[63 - i*2 - 1].i = temp4;
    }
}
