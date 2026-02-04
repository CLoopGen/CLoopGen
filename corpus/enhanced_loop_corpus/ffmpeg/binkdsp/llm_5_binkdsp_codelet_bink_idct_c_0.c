#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *block;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    {
        const int base = 8 * i;
        int local_temp[8];
        for (int j = 0; j < 8; j++) {
            local_temp[j] = temp[base + j];
        }

        const int a0 = local_temp[0] + local_temp[4];
        const int a1 = local_temp[0] - local_temp[4];
        const int a2 = local_temp[2] + local_temp[6];
        const int a3 = ((int)((unsigned int)(2896) * (local_temp[2] - local_temp[6])) >> 11);
        const int a4 = local_temp[5] + local_temp[3];
        const int a5 = local_temp[5] - local_temp[3];
        const int a6 = local_temp[1] + local_temp[7];
        const int a7 = local_temp[1] - local_temp[7];

        const int b0 = a4 + a6;
        const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
        const int b2 = ((int)((unsigned int)(-5352) * a5) >> 11) - b0 + b1;
        const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
        const int b4 = ((int)((unsigned int)(2217) * a7) >> 11) + b3 - b1;

        block[base + 0] = (a0 + a2 + b0 + 127) >> 8;
        block[base + 1] = (a1 + a3 - a2 + b2 + 127) >> 8;
        block[base + 2] = (a1 - a3 + a2 + b3 + 127) >> 8;
        block[base + 3] = (a0 - a2 - b4 + 127) >> 8;
        block[base + 4] = (a0 - a2 + b4 + 127) >> 8;
        block[base + 5] = (a1 - a3 + a2 - b3 + 127) >> 8;
        block[base + 6] = (a1 + a3 - a2 - b2 + 127) >> 8;
        block[base + 7] = (a0 + a2 - b0 + 127) >> 8;
    }
}
}
