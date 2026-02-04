#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive array access via local buffer to improve spatial locality
    for (i = 0; i < 8; i++) {
        int32_t local_coef[8];
        int32_t local_tmp[8];

        // Strided-to-consecutive copy: gather strided data into contiguous buffer
        for (int j = 0; j < 8; j++) {
            local_coef[j] = (coef + i)[j * 8];
        }

        const int a0 = local_coef[0] + local_coef[7];
        const int a1 = local_coef[0] - local_coef[7];
        const int a2 = local_coef[1] + local_coef[6];
        const int a3 = local_coef[1] - local_coef[6];
        const int a4 = local_coef[2] + local_coef[5];
        const int a5 = local_coef[2] - local_coef[5];
        const int a6 = local_coef[3] + local_coef[4];
        const int a7 = local_coef[3] - local_coef[4];

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));

        local_tmp[0] = b0 + b1;
        local_tmp[1] = b4 + (b7 >> 2);
        local_tmp[2] = b2 + (b3 >> 1);
        local_tmp[3] = b5 + (b6 >> 2);
        local_tmp[4] = b0 - b1;
        local_tmp[5] = b6 - (b5 >> 2);
        local_tmp[6] = (b2 >> 1) - b3;
        local_tmp[7] = (b4 >> 2) - b7;

        // Scatter result back with original strided pattern
        for (int j = 0; j < 8; j++) {
            (tmp + i)[j * 8] = local_tmp[j];
        }
    }
}
