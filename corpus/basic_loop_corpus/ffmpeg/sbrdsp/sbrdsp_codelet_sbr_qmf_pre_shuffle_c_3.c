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
    zi[64 + 2 * k + 0].i = zi[64 - k].i ^ (1U << 31);
    zi[64 + 2 * k + 1].i = zi[k + 1].i;
    zi[64 + 2 * k + 2].i = zi[63 - k].i ^ (1U << 31);
    zi[64 + 2 * k + 3].i = zi[k + 2].i;
}

}
