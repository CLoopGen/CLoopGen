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
for (i = 0; i < 16; i += 2) {
    {
        const int base_idx = 8 * i;
        const int a0 = temp[base_idx + 0] + temp[base_idx + 4];
        const int a1 = temp[base_idx + 0] - temp[base_idx + 4];
        const int a2 = temp[base_idx + 2] + temp[base_idx + 6];
        const int a3 = ((int)((unsigned int)(2896) * (temp[base_idx + 2] - temp[base_idx + 6])) >> 11);
        const int a4 = temp[base_idx + 5] + temp[base_idx + 3];
        const int a5 = temp[base_idx + 5] - temp[base_idx + 3];
        const int a6 = temp[base_idx + 1] + temp[base_idx + 7];
        const int a7 = temp[base_idx + 1] - temp[base_idx + 7];
        const int b0 = a4 + a6;
        const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
        const int b2 = ((int)((unsigned int)(-5352) * a5) >> 11) - b0 + b1;
        const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
        const int b4 = ((int)((unsigned int)(2217) * a7) >> 11) + b3 - b1;
        const int out_val_0 = ((a0 + a2 + b0) + 127) >> 8;
        const int out_val_1 = ((a1 + a3 - a2 + b2) + 127) >> 8;
        const int out_val_2 = ((a1 - a3 + a2 + b3) + 127) >> 8;
        const int out_val_3 = ((a0 - a2 - b4) + 127) >> 8;
        const int out_val_4 = ((a0 - a2 + b4) + 127) >> 8;
        const int out_val_5 = ((a1 - a3 + a2 - b3) + 127) >> 8;
        const int out_val_6 = ((a1 + a3 - a2 - b2) + 127) >> 8;
        const int out_val_7 = ((a0 + a2 - b0) + 127) >> 8;
        dest[i * linesize + 0] = out_val_0;
        dest[i * linesize + 1] = out_val_1;
        dest[i * linesize + 2] = out_val_2;
        dest[i * linesize + 3] = out_val_3;
        dest[i * linesize + 4] = out_val_4;
        dest[i * linesize + 5] = out_val_5;
        dest[i * linesize + 6] = out_val_6;
        dest[i * linesize + 7] = out_val_7;
        if (i + 1 < 16) {
            const int next_idx = 8 * (i + 1);
            const int na0 = temp[next_idx + 0] + temp[next_idx + 4];
            const int na1 = temp[next_idx + 0] - temp[next_idx + 4];
            const int na2 = temp[next_idx + 2] + temp[next_idx + 6];
            const int na3 = ((int)((unsigned int)(2896) * (temp[next_idx + 2] - temp[next_idx + 6])) >> 11);
            const int na4 = temp[next_idx + 5] + temp[next_idx + 3];
            const int na5 = temp[next_idx + 5] - temp[next_idx + 3];
            const int na6 = temp[next_idx + 1] + temp[next_idx + 7];
            const int na7 = temp[next_idx + 1] - temp[next_idx + 7];
            const int nb0 = na4 + na6;
            const int nb1 = ((int)((unsigned int)(3784) * (na5 + na7)) >> 11);
            const int nb2 = ((int)((unsigned int)(-5352) * na5) >> 11) - nb0 + nb1;
            const int nb3 = ((int)((unsigned int)(2896) * (na6 - na4)) >> 11) - nb2;
            const int nb4 = ((int)((unsigned int)(2217) * na7) >> 11) + nb3 - nb1;
            dest[(i + 1) * linesize + 0] = ((na0 + na2 + nb0) + 127) >> 8;
            dest[(i + 1) * linesize + 1] = ((na1 + na3 - na2 + nb2) + 127) >> 8;
            dest[(i + 1) * linesize + 2] = ((na1 - na3 + na2 + nb3) + 127) >> 8;
            dest[(i + 1) * linesize + 3] = ((na0 - na2 - nb4) + 127) >> 8;
            dest[(i + 1) * linesize + 4] = ((na0 - na2 + nb4) + 127) >> 8;
            dest[(i + 1) * linesize + 5] = ((na1 - na3 + na2 - nb3) + 127) >> 8;
            dest[(i + 1) * linesize + 6] = ((na1 + na3 - na2 - nb2) + 127) >> 8;
            dest[(i + 1) * linesize + 7] = ((na0 + na2 - nb0) + 127) >> 8;
        }
    }
}
}
