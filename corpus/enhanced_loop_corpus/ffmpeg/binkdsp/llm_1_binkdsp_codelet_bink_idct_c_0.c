#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *block;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 8) {
    {
        const int a0 = temp[i + 0] + temp[i + 4];
        const int a1 = temp[i + 0] - temp[i + 4];
        const int a2 = temp[i + 2] + temp[i + 6];
        const int a3 = ((int)((unsigned int)(2896) * (temp[i + 2] - temp[i + 6])) >> 11);
        const int a4 = temp[i + 5] + temp[i + 3];
        const int a5 = temp[i + 5] - temp[i + 3];
        const int a6 = temp[i + 1] + temp[i + 7];
        const int a7 = temp[i + 1] - temp[i + 7];
        const int b0 = a4 + a6;
        const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
        const int b2 = ((int)((unsigned int)(-5352) * (a5)) >> 11) - b0 + b1;
        const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
        const int b4 = ((int)((unsigned int)(2217) * (a7)) >> 11) + b3 - b1;
        block[i + 0] = ((a0 + a2 + b0) + 127) >> 8;
        block[i + 1] = ((a1 + a3 - a2 + b2) + 127) >> 8;
        block[i + 2] = ((a1 - a3 + a2 + b3) + 127) >> 8;
        block[i + 3] = ((a0 - a2 - b4) + 127) >> 8;
        block[i + 4] = ((a0 - a2 + b4) + 127) >> 8;
        block[i + 5] = ((a1 - a3 + a2 - b3) + 127) >> 8;
        block[i + 6] = ((a1 + a3 - a2 - b2) + 127) >> 8;
        block[i + 7] = ((a0 + a2 - b0) + 127) >> 8;
    }
}
}
