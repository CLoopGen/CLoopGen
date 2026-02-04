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
    for (i = 0; i < 64; i += 2) {
        int idx1 = 63 - i;
        int idx2 = 63 - i - 1;
        vi[i/2].i = si[idx1].i;
        if (idx2 >= 0) {
            vi[63 - i/2].i = si[idx2].i ^ (1U << 31);
        }
    }
}
