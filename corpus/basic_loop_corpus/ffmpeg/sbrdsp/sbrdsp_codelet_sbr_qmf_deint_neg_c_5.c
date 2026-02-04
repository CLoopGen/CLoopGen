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
for (i = 0; i < 32; i++) {
    vi[i].i = si[63 - 2 * i].i;
    vi[63 - i].i = si[63 - 2 * i - 1].i ^ (1U << 31);
}

}
