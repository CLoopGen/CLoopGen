#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    const int idx1 = i, idx2 = i+1;
    const int a0_1 = (coef + idx1)[8 * 0] + (coef + idx1)[8 * 7];
    const int a1_1 = (coef + idx1)[8 * 0] - (coef + idx1)[8 * 7];
    const int a2_1 = (coef + idx1)[8 * 1] + (coef + idx1)[8 * 6];
    const int a3_1 = (coef + idx1)[8 * 1] - (coef + idx1)[8 * 6];
    const int a4_1 = (coef + idx1)[8 * 2] + (coef + idx1)[8 * 5];
    const int a5_1 = (coef + idx1)[8 * 2] - (coef + idx1)[8 * 5];
    const int a6_1 = (coef + idx1)[8 * 3] + (coef + idx1)[8 * 4];
    const int a7_1 = (coef + idx1)[8 * 3] - (coef + idx1)[8 * 4];

    const int a0_2 = (coef + idx2)[8 * 0] + (coef + idx2)[8 * 7];
    const int a1_2 = (coef + idx2)[8 * 0] - (coef + idx2)[8 * 7];
    const int a2_2 = (coef + idx2)[8 * 1] + (coef + idx2)[8 * 6];
    const int a3_2 = (coef + idx2)[8 * 1] - (coef + idx2)[8 * 6];
    const int a4_2 = (coef + idx2)[8 * 2] + (coef + idx2)[8 * 5];
    const int a5_2 = (coef + idx2)[8 * 2] - (coef + idx2)[8 * 5];
    const int a6_2 = (coef + idx2)[8 * 3] + (coef + idx2)[8 * 4];
    const int a7_2 = (coef + idx2)[8 * 3] - (coef + idx2)[8 * 4];

    const int b0_1 = a0_1 + a6_1;
    const int b1_1 = a2_1 + a4_1;
    const int b2_1 = a0_1 - a6_1;
    const int b3_1 = a2_1 - a4_1;
    const int b4_1 = a3_1 + a5_1 + (a1_1 + (a1_1 >> 1));
    const int b5_1 = a1_1 - a7_1 - (a5_1 + (a5_1 >> 1));
    const int b6_1 = a1_1 + a7_1 - (a3_1 + (a3_1 >> 1));
    const int b7_1 = a3_1 - a5_1 + (a7_1 + (a7_1 >> 1));

    const int b0_2 = a0_2 + a6_2;
    const int b1_2 = a2_2 + a4_2;
    const int b2_2 = a0_2 - a6_2;
    const int b3_2 = a2_2 - a4_2;
    const int b4_2 = a3_2 + a5_2 + (a1_2 + (a1_2 >> 1));
    const int b5_2 = a1_2 - a7_2 - (a5_2 + (a5_2 >> 1));
    const int b6_2 = a1_2 + a7_2 - (a3_2 + (a3_2 >> 1));
    const int b7_2 = a3_2 - a5_2 + (a7_2 + (a7_2 >> 1));

    (tmp + idx1)[8 * 0] = b0_1 + b1_1;
    (tmp + idx1)[8 * 1] = b4_1 + (b7_1 >> 2);
    (tmp + idx1)[8 * 2] = b2_1 + (b3_1 >> 1);
    (tmp + idx1)[8 * 3] = b5_1 + (b6_1 >> 2);
    (tmp + idx1)[8 * 4] = b0_1 - b1_1;
    (tmp + idx1)[8 * 5] = b6_1 - (b5_1 >> 2);
    (tmp + idx1)[8 * 6] = (b2_1 >> 1) - b3_1;
    (tmp + idx1)[8 * 7] = (b4_1 >> 2) - b7_1;

    if (idx2 < 8) {
        (tmp + idx2)[8 * 0] = b0_2 + b1_2;
        (tmp + idx2)[8 * 1] = b4_2 + (b7_2 >> 2);
        (tmp + idx2)[8 * 2] = b2_2 + (b3_2 >> 1);
        (tmp + idx2)[8 * 3] = b5_2 + (b6_2 >> 2);
        (tmp + idx2)[8 * 4] = b0_2 - b1_2;
        (tmp + idx2)[8 * 5] = b6_2 - (b5_2 >> 2);
        (tmp + idx2)[8 * 6] = (b2_2 >> 1) - b3_2;
        (tmp + idx2)[8 * 7] = (b4_2 >> 2) - b7_2;
    }
}
}
