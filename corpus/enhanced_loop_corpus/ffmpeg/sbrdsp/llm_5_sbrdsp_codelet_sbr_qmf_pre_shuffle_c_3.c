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
        int index_offset = 64 + 2 * k;
        if ((zi[k + 1].i & 1) == 0) {
            zi[index_offset + 0].i = zi[64 - k].i ^ (1U << 31);
            zi[index_offset + 1].i = zi[k + 1].i;
        } else {
            zi[index_offset + 0].i = zi[63 - k].i ^ (1U << 31);
        }
        zi[index_offset + 2].i = zi[63 - k].i ^ (1U << 31);
        zi[index_offset + 3].i = zi[k + 2].i;
    }
}
