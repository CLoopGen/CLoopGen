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
    for (i = 0; i < 8; i += 2) {
        for (int j = 0; j < 2; j++) {
            const int idx = i + j;
            if (idx >= 8) continue;
            {
                const int a0 = ((&temp[8 * idx]))[0] + ((&temp[8 * idx]))[4];
                const int a1 = ((&temp[8 * idx]))[0] - ((&temp[8 * idx]))[4];
                const int a2 = ((&temp[8 * idx]))[2] + ((&temp[8 * idx]))[6];
                const int a3 = ((int)((unsigned int)(2896) * (((&temp[8 * idx]))[2] - ((&temp[8 * idx]))[6])) >> 11);
                const int a4 = ((&temp[8 * idx]))[5] + ((&temp[8 * idx]))[3];
                const int a5 = ((&temp[8 * idx]))[5] - ((&temp[8 * idx]))[3];
                const int a6 = ((&temp[8 * idx]))[1] + ((&temp[8 * idx]))[7];
                const int a7 = ((&temp[8 * idx]))[1] - ((&temp[8 * idx]))[7];
                const int b0 = a4 + a6;
                const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
                const int b2 = ((int)((unsigned int)(-5352) * (a5)) >> 11) - b0 + b1;
                const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
                const int b4 = ((int)((unsigned int)(2217) * (a7)) >> 11) + b3 - b1;
                ((&dest[idx * linesize]))[0] = (((a0 + a2 + b0) + 127) >> 8);
                ((&dest[idx * linesize]))[1] = (((a1 + a3 - a2 + b2) + 127) >> 8);
                ((&dest[idx * linesize]))[2] = (((a1 - a3 + a2 + b3) + 127) >> 8);
                ((&dest[idx * linesize]))[3] = (((a0 - a2 - b4) + 127) >> 8);
                ((&dest[idx * linesize]))[4] = (((a0 - a2 + b4) + 127) >> 8);
                ((&dest[idx * linesize]))[5] = (((a1 - a3 + a2 - b3) + 127) >> 8);
                ((&dest[idx * linesize]))[6] = (((a1 + a3 - a2 - b2) + 127) >> 8);
                ((&dest[idx * linesize]))[7] = (((a0 + a2 - b0) + 127) >> 8);
            }
        }
    }
}
