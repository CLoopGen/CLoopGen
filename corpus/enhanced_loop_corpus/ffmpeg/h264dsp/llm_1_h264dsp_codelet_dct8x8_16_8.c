#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
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
            const int b4 = a3 + a5 + (a1 + (a1 >> 1));
            const int b5 = a1 - a7 - (a5 + (a5 >> 1));
            const int b6 = a1 + a7 - (a3 + (a3 >> 1));
            const int b7 = a3 - a5 + (a7 + (a7 >> 1));
            (tmp + i)[8 * 0] = b0 + b1;
            (tmp + i)[8 * 1] = b4 + (b7 >> 2);
            (tmp + i)[8 * 2] = b2 + (b3 >> 1);
            (tmp + i)[8 * 3] = b5 + (b6 >> 2);
            (tmp + i)[8 * 4] = b0 - b1;
            (tmp + i)[8 * 5] = b6 - (b5 >> 2);
            (tmp + i)[8 * 6] = (b2 >> 1) - b3;
            (tmp + i)[8 * 7] = (b4 >> 2) - b7;
        }
    }
}
