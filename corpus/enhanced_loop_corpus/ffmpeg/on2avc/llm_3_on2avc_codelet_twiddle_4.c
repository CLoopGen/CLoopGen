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
for (i = 0; i < steps; i++) {
    float in0 = src1[order0 + i];
    int pos = (src2_len - 1) & mask;
    if (pos < tab_len) {
        const double *t = tab + pos;
        for (j = pos; j >= 0; j--) {
            src2[j] += in0 * t[pos - j];
        }
        for (j = 0; j < tab_len - pos - 1; j++) {
            src2[src2_len - j - 1] += in0 * t[pos + 1 + j];
        }
    } else {
        const double *t = tab;
        int base_idx = pos - tab_len + 1;
        for (j = 0; j < tab_len; j++) {
            src2[base_idx + j] += in0 * t[j];
        }
    }
    mask = pos + step;
}
}
