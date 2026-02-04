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
    for (k = 0; k < 16; k++) {
        uint32_t mask = (1U << 31);
        int rev_k = 63 - k;
        int offset = 4 * k;
        Wi[offset].i     = zi[rev_k].i ^ mask;
        Wi[offset + 1].i = zi[k].i;
    }
}
