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
    if (pos < tab_len && tab_len > 0) {
        const double *t = tab;
        j = pos;
        while (j >= 0 && j >= pos - 3) {
            src2[j] += in0 * *t++;
            j--;
        }
        for (; j >= 0; j--)
            src2[j] += in0 * *t++;

        for (j = 0; j < tab_len - pos - 1 && j < 4; j++)
            src2[src2_len - j - 1] += in0 * tab[pos + 1 + j];
        for (; j < tab_len - pos - 1; j++)
            src2[src2_len - j - 1] += in0 * tab[pos + 1 + j];
    } else if (tab_len > 0) {
        j = 0;
        for (; j < tab_len && j < 8; j += 2) {
            src2[pos - j] += in0 * tab[j];
            if (j + 1 < tab_len)
                src2[pos - (j + 1)] += in0 * tab[j + 1];
        }
        for (; j < tab_len; j++) {
            src2[pos - j] += in0 * tab[j];
        }
    }
    mask = pos + step;
}
}
