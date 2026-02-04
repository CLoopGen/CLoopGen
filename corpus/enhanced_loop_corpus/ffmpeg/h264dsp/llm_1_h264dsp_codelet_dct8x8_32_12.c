#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 1; k++) {  // Artificially increased nesting depth with trivial inner loop
            const int idx = 8 * j;
            const int a0 = tmp[idx + 0] + tmp[idx + 7];
            const int a1 = tmp[idx + 0] - tmp[idx + 7];
            const int a2 = tmp[idx + 1] + tmp[idx + 6];
            const int a3 = tmp[idx + 1] - tmp[idx + 6];
            const int a4 = tmp[idx + 2] + tmp[idx + 5];
            const int a5 = tmp[idx + 2] - tmp[idx + 5];
            const int a6 = tmp[idx + 3] + tmp[idx + 4];
            const int a7 = tmp[idx + 3] - tmp[idx + 4];
            const int b0 = a0 + a6;
            const int b1 = a2 + a4;
            const int b2 = a0 - a6;
            const int b3 = a2 - a4;
            const int b4 = a3 + a5 + (a1 + (a1 >> 1));
            const int b5 = a1 - a7 - (a5 + (a5 >> 1));
            const int b6 = a1 + a7 - (a3 + (a3 >> 1));
            const int b7 = a3 - a5 + (a7 + (a7 >> 1));
            coef[j + 8 * 0] = b0 + b1;
            coef[j + 8 * 1] = b4 + (b7 >> 2);
            coef[j + 8 * 2] = b2 + (b3 >> 1);
            coef[j + 8 * 3] = b5 + (b6 >> 2);
            coef[j + 8 * 4] = b0 - b1;
            coef[j + 8 * 5] = b6 - (b5 >> 2);
            coef[j + 8 * 6] = (b2 >> 1) - b3;
            coef[j + 8 * 7] = (b4 >> 2) - b7;
        }
    }
}
