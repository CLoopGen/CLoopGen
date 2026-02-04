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
    for (k = 0; k < 32; k += 2) {
        uint32_t temp1 = zi[63 - k].i ^ (1U << 31);
        uint32_t temp2 = zi[62 - k].i ^ (1U << 31);
        uint32_t val_k0 = zi[k + 0].i;
        uint32_t val_k1 = zi[k + 1].i;

        if (val_k0 > val_k1) {
            Wi[2 * k + 0].i = temp1;
            Wi[2 * k + 2].i = temp2;
            Wi[2 * k + 1].i = val_k0;
            Wi[2 * k + 3].i = val_k1;
        } else {
            Wi[2 * k + 0].i = val_k0;
            Wi[2 * k + 2].i = val_k1;
            Wi[2 * k + 1].i = temp1;
            Wi[2 * k + 3].i = temp2;
        }
    }
}
