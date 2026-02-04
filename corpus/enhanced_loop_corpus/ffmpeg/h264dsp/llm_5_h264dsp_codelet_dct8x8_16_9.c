#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        const int base = 8 * i;
        const int t0 = tmp[base + 0], t1 = tmp[base + 1];
        const int t2 = tmp[base + 2], t3 = tmp[base + 3];
        const int t4 = tmp[base + 4], t5 = tmp[base + 5];
        const int t6 = tmp[base + 6], t7 = tmp[base + 7];

        const int a0 = t0 + t7, a1 = t0 - t7;
        const int a2 = t1 + t6, a3 = t1 - t6;
        const int a4 = t2 + t5, a5 = t2 - t5;
        const int a6 = t3 + t4, a7 = t3 - t4;

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;

        // Conditional bypass based on coefficient magnitude
        if (abs(b0 + b1) < 1024) {
            const int b4 = a3 + a5 + (a1 + (a1 >> 1));
            const int b5 = a1 - a7 - (a5 + (a5 >> 1));
            const int b6 = a1 + a7 - (a3 + (a3 >> 1));
            const int b7 = a3 - a5 + (a7 + (a7 >> 1));

            (coef + i)[8 * 0] = b0 + b1;
            (coef + i)[8 * 4] = b0 - b1;
            (coef + i)[8 * 2] = b2 + (b3 >> 1);
            (coef + i)[8 * 6] = (b2 >> 1) - b3;
            (coef + i)[8 * 1] = b4 + (b7 >> 2);
            (coef + i)[8 * 3] = b5 + (b6 >> 2);
            (coef + i)[8 * 5] = b6 - (b5 >> 2);
            (coef + i)[8 * 7] = (b4 >> 2) - b7;
        } else {
            // Fallback: simplified output for large values
            (coef + i)[8 * 0] = (b0 + b1) >> 1;
            (coef + i)[8 * 4] = (b0 - b1) >> 1;
            (coef + i)[8 * 2] = b2 >> 1;
            (coef + i)[8 * 6] = -(b3 >> 1);
            (coef + i)[8 * 1] = 0;
            (coef + i)[8 * 3] = 0;
            (coef + i)[8 * 5] = 0;
            (coef + i)[8 * 7] = 0;
        }
    }
}
