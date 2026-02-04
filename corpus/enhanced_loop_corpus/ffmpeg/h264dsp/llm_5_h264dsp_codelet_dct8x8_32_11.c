#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        const int idx_base = i;
        const int c0 = coef[8 * 0 + idx_base], c7 = coef[8 * 7 + idx_base];
        const int c1 = coef[8 * 1 + idx_base], c6 = coef[8 * 6 + idx_base];
        const int c2 = coef[8 * 2 + idx_base], c5 = coef[8 * 5 + idx_base];
        const int c3 = coef[8 * 3 + idx_base], c4 = coef[8 * 4 + idx_base];

        const int a0 = c0 + c7;
        const int a1 = c0 - c7;
        const int a2 = c1 + c6;
        const int a3 = c1 - c6;
        const int a4 = c2 + c5;
        const int a5 = c2 - c5;
        const int a6 = c3 + c4;
        const int a7 = c3 - c4;

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;

        // Introduce conditional early skip based on symmetry condition
        if (a1 == 0 && a3 == 0 && a5 == 0 && a7 == 0) {
            // Exploit symmetry: even-like behavior, simplified outputs
            tmp[8 * 0 + idx_base] = b0 + b1;
            tmp[8 * 2 + idx_base] = b2 + (b3 >> 1);
            tmp[8 * 4 + idx_base] = b0 - b1;
            tmp[8 * 6 + idx_base] = (b2 >> 1) - b3;

            // Odd-indexed outputs collapse due to zero odd components
            tmp[8 * 1 + idx_base] = 0;
            tmp[8 * 3 + idx_base] = 0;
            tmp[8 * 5 + idx_base] = 0;
            tmp[8 * 7 + idx_base] = 0;
            continue;
        }

        // General case computation (original logic)
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));

        tmp[8 * 0 + idx_base] = b0 + b1;
        tmp[8 * 1 + idx_base] = b4 + (b7 >> 2);
        tmp[8 * 2 + idx_base] = b2 + (b3 >> 1);
        tmp[8 * 3 + idx_base] = b5 + (b6 >> 2);
        tmp[8 * 4 + idx_base] = b0 - b1;
        tmp[8 * 5 + idx_base] = b6 - (b5 >> 2);
        tmp[8 * 6 + idx_base] = (b2 >> 1) - b3;
        tmp[8 * 7 + idx_base] = (b4 >> 2) - b7;
    }
}
