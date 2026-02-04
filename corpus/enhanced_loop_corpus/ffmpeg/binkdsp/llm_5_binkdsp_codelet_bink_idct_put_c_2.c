#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest;
extern int linesize;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int base = 8 * i;
    const int* src = &temp[base];
    uint8_t* dst = &dest[i * linesize];

    const int a0 = src[0] + src[4];
    const int a1 = src[0] - src[4];
    const int a2 = src[2] + src[6];
    const int a3 = ((int)((unsigned int)(2896) * (src[2] - src[6])) >> 11);

    if (a0 >= 0) {
        const int a4 = src[5] + src[3];
        const int a5 = src[5] - src[3];
        const int a6 = src[1] + src[7];
        const int a7 = src[1] - src[7];
        const int b0 = a4 + a6;
        const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
        const int b2 = ((int)((unsigned int)(-5352) * a5) >> 11) - b0 + b1;
        const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
        const int b4 = ((int)((unsigned int)(2217) * a7) >> 11) + b3 - b1;

        dst[0] = ((a0 + a2 + b0 + 127) >> 8);
        dst[1] = ((a1 + a3 - a2 + b2 + 127) >> 8);
        dst[2] = ((a1 - a3 + a2 + b3 + 127) >> 8);
        dst[3] = ((a0 - a2 - b4 + 127) >> 8);
        dst[4] = ((a0 - a2 + b4 + 127) >> 8);
        dst[5] = ((a1 - a3 + a2 - b3 + 127) >> 8);
        dst[6] = ((a1 + a3 - a2 - b2 + 127) >> 8);
        dst[7] = ((a0 + a2 - b0 + 127) >> 8);
    } else {
        const int mid = (src[0] + src[7]) >> 1;
        for (int k = 0; k < 8; ++k) {
            dst[k] = (mid + 127) >> 8;
        }
    }
}
}
