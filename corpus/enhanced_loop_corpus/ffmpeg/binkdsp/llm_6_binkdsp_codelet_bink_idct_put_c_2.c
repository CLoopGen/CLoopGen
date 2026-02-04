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
    {
        const int t0 = temp[8 * i + 0];
        const int t1 = temp[8 * i + 1];
        const int t2 = temp[8 * i + 2];
        const int t3 = temp[8 * i + 3];
        const int t4 = temp[8 * i + 4];
        const int t5 = temp[8 * i + 5];
        const int t6 = temp[8 * i + 6];
        const int t7 = temp[8 * i + 7];

        const int a0 = t0 + t4;
        const int a1 = t0 - t4;
        const int a2 = t2 + t6;
        const int a3 = ((int)((unsigned int)(2896) * (t2 - t6)) >> 11);
        const int a4 = t5 + t3;
        const int a5 = t5 - t3;
        const int a6 = t1 + t7;
        const int a7 = t1 - t7;

        const int b0 = a4 + a6;
        const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
        const int b2 = ((int)((unsigned int)(-5352) * a5) >> 11) - b0 + b1;
        const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
        const int b4 = ((int)((unsigned int)(2217) * a7) >> 11) + b3 - b1;

        const int c0 = a0 + a2 + b0;
        const int c1 = a1 + a3 - a2 + b2;
        const int c2 = a1 - a3 + a2 + b3;
        const int c3 = a0 - a2 - b4;
        const int c4 = a0 - a2 + b4;
        const int c5 = a1 - a3 + a2 - b3;
        const int c6 = a1 + a3 - a2 - b2;
        const int c7 = a0 + a2 - b0;

        dest[i * linesize + 0] = (c0 + 127) >> 8;
        dest[i * linesize + 1] = (c1 + 127) >> 8;
        dest[i * linesize + 2] = (c2 + 127) >> 8;
        dest[i * linesize + 3] = (c3 + 127) >> 8;
        dest[i * linesize + 4] = (c4 + 127) >> 8;
        dest[i * linesize + 5] = (c5 + 127) >> 8;
        dest[i * linesize + 6] = (c6 + 127) >> 8;
        dest[i * linesize + 7] = (c7 + 127) >> 8;
    }
}
}
