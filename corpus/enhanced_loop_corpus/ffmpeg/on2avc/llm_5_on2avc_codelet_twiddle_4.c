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
    const double *t = tab;
    int limit = (pos < tab_len) ? pos + 1 : tab_len;
    for (j = 0; j < limit; j++) {
        if (pos < tab_len) {
            src2[pos - j] += in0 * t[j];
        } else {
            src2[pos - j] += in0 * t[j];
        }
    }
    if (pos < tab_len) {
        for (j = 0; j < tab_len - pos - 1; j++) {
            src2[src2_len - j - 1] += in0 * tab[pos + 1 + j];
        }
    }
    mask = pos + step;
}
}
