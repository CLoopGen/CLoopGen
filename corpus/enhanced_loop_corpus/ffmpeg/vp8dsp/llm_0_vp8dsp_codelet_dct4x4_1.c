#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; k++) {
        for (i = 0; i < 2; i++) {
            const int a1 = (coef[i * 4 + 0] + coef[i * 4 + 3]) * 8;
            const int b1 = (coef[i * 4 + 1] + coef[i * 4 + 2]) * 8;
            const int c1 = (coef[i * 4 + 1] - coef[i * 4 + 2]) * 8;
            const int d1 = (coef[i * 4 + 0] - coef[i * 4 + 3]) * 8;
            coef[i * 4 + 0] = a1 + b1;
            coef[i * 4 + 1] = (c1 * 2217 + d1 * 5352 + 14500) >> 12;
            coef[i * 4 + 2] = a1 - b1;
            coef[i * 4 + 3] = (d1 * 2217 - c1 * 5352 + 7500) >> 12;
        }
    }
}
