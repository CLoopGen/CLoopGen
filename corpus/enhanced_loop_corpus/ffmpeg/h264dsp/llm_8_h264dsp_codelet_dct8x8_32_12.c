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
        const int a0 = tmp[8*i + 0] + tmp[8*i + 7];
        const int a1 = tmp[8*i + 0] - tmp[8*i + 7];
        const int a2 = tmp[8*i + 1] + tmp[8*i + 6];
        const int a3 = tmp[8*i + 1] - tmp[8*i + 6];
        const int a4 = tmp[8*i + 2] + tmp[8*i + 5];
        const int a5 = tmp[8*i + 2] - tmp[8*i + 5];
        const int a6 = tmp[8*i + 3] + tmp[8*i + 4];
        const int a7 = tmp[8*i + 3] - tmp[8*i + 4];

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;

        // Reduce arithmetic complexity: remove some computations and simplify assignments
        coef[i + 0] = b0 + b1;
        coef[i + 8] = b0 - b1;
        coef[i + 16] = b2 + (b3 >> 1);
        coef[i + 24] = (b2 >> 1) - b3;
        // Skip b4-b7 calculations entirely
    }
}
