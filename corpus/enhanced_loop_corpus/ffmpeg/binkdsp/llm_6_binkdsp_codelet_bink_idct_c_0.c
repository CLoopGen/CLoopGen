#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *block;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    {
        const int a0 = ((&temp[8 * i]))[0] + ((&temp[8 * i]))[4];
        const int a1 = ((&temp[8 * i]))[0] - ((&temp[8 * i]))[4];
        const int a2 = ((&temp[8 * i]))[2] + ((&temp[8 * i]))[6];
        const int a3 = ((int)((unsigned int)(2896) * (((&temp[8 * i]))[2] - ((&temp[8 * i]))[6])) >> 11);
        const int b0 = ((&temp[8 * i]))[5] + ((&temp[8 * i]))[1];
        const int b1 = ((int)((unsigned int)(3784) * (((&temp[8 * i]))[5] - ((&temp[8 * i]))[1])) >> 11);
        ((&block[8 * i]))[0] = (((a0 + a2 + b0) + 127) >> 8);
        ((&block[8 * i]))[1] = (((a1 + a3 - a2 + b1) + 127) >> 8);
        ((&block[8 * i]))[2] = (((a1 - a3 + a2) + 127) >> 8);
        ((&block[8 * i]))[3] = (((a0 - a2) + 127) >> 8);
        ((&block[8 * i]))[4] = (((a0 - a2) + 127) >> 8);
        ((&block[8 * i]))[5] = (((a1 - a3 + a2) + 127) >> 8);
        ((&block[8 * i]))[6] = (((a1 + a3 - a2) + 127) >> 8);
        ((&block[8 * i]))[7] = (((a0 + a2) + 127) >> 8);
    }
}
}
