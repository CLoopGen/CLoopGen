#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int32_t *base_coef = coef + i;
        int32_t *base_tmp = tmp + i;
        const int stride = 8;
        const int idx0 = 0 * stride, idx1 = 1 * stride, idx2 = 2 * stride, idx3 = 3 * stride;
        const int idx4 = 4 * stride, idx5 = 5 * stride, idx6 = 6 * stride, idx7 = 7 * stride;

        const int a0 = base_coef[idx0] + base_coef[idx7];
        const int a1 = base_coef[idx0] - base_coef[idx7];
        const int a2 = base_coef[idx1] + base_coef[idx6];
        const int a3 = base_coef[idx1] - base_coef[idx6];
        const int a4 = base_coef[idx2] + base_coef[idx5];
        const int a5 = base_coef[idx2] - base_coef[idx5];
        const int a6 = base_coef[idx3] + base_coef[idx4];
        const int a7 = base_coef[idx3] - base_coef[idx4];

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));

        base_tmp[idx0] = b0 + b1;
        base_tmp[idx1] = b4 + (b7 >> 2);
        base_tmp[idx2] = b2 + (b3 >> 1);
        base_tmp[idx3] = b5 + (b6 >> 2);
        base_tmp[idx4] = b0 - b1;
        base_tmp[idx5] = b6 - (b5 >> 2);
        base_tmp[idx6] = (b2 >> 1) - b3;
        base_tmp[idx7] = (b4 >> 2) - b7;
    }
}
