#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src1;
extern float *src2;
extern int src2_len;
extern  double *tab;
extern int tab_len;
extern int step;
extern int order0;
extern int steps;
extern int mask;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < steps; i += 2) {
    float in0_0 = src1[order0 + i];
    float in0_1 = (i + 1 < steps) ? src1[order0 + i + 1] : 0.0f;
    int pos0 = (src2_len - 1) & mask;
    int pos1 = (src2_len - 1) & (mask + step);
    const double *t0 = tab;
    const double *t1 = tab;

    if (pos0 < tab_len) {
        for (j = pos0; j >= 0; j--) {
            src2[j] += in0_0 * (*t0++);
        }
        for (j = 0; j < tab_len - pos0 - 1; j++) {
            src2[src2_len - j - 1] += in0_0 * tab[pos0 + 1 + j];
        }
    } else {
        for (j = 0; j < tab_len; j++) {
            src2[pos0 - j] += in0_0 * tab[j];
        }
    }

    if (i + 1 < steps) {
        if (pos1 < tab_len) {
            for (j = pos1; j >= 0; j--) {
                src2[j] += in0_1 * (*t1++);
            }
            for (j = 0; j < tab_len - pos1 - 1; j++) {
                src2[src2_len - j - 1] += in0_1 * tab[pos1 + 1 + j];
            }
        } else {
            for (j = 0; j < tab_len; j++) {
                src2[pos1 - j] += in0_1 * tab[j];
            }
        }
    }

    mask = pos1 + step;
}
}
