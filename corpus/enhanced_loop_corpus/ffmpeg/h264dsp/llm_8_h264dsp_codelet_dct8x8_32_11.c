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
        const int a0 = (coef + i)[8 * 0] + (coef + i)[8 * 7];
        const int a1 = (coef + i)[8 * 0] - (coef + i)[8 * 7];
        const int a2 = (coef + i)[8 * 1] + (coef + i)[8 * 6];
        const int a3 = (coef + i)[8 * 1] - (coef + i)[8 * 6];
        const int a4 = (coef + i)[8 * 2] + (coef + i)[8 * 5];
        const int a5 = (coef + i)[8 * 2] - (coef + i)[8 * 5];
        const int a6 = (coef + i)[8 * 3] + (coef + i)[8 * 4];
        const int a7 = (coef + i)[8 * 3] - (coef + i)[8 * 4];

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;

        // Simplified computation: remove complex bit-shift arithmetic
        const int b4 = a1 + a3;
        const int b5 = a1 - a5;
        const int b6 = a7 + a5;
        const int b7 = a7 - a3;

        (tmp + i)[8 * 0] = b0 + b1;
        (tmp + i)[8 * 1] = b4;
        (tmp + i)[8 * 2] = b2 + b3;
        (tmp + i)[8 * 3] = b5;
        (tmp + i)[8 * 4] = b0 - b1;
        (tmp + i)[8 * 5] = b6;
        (tmp + i)[8 * 6] = b2 - b3;
        (tmp + i)[8 * 7] = b4 - b7;
    }
}
