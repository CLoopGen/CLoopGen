#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int len;
extern int order;
extern  int32_t *coefs;
extern int shift;
extern int big;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = order; i < len; i += 2) {
    int32_t p0 = 0, p1 = 0;
    const int stride = 2;
    if (big) {
        for (int j = 0; j < order; j += stride) {
            int idx0 = (order - 1) - j;
            int idx1 = (order - 1) - j - 1;
            int s0 = smp[i - order + j];
            int s1 = smp[i - order + j + 1];
            p0 += coefs[idx0] * s0;
            p1 += coefs[idx0] * s1;
            if (j + 1 < order) {
                p0 += coefs[idx1] * s1;
                p1 += coefs[idx1] * smp[i - order + j + 2];
            }
        }
    } else {
        for (int j = 0; j < order; j += stride) {
            int idx0 = (order - 1) - j;
            int idx1 = (order - 1) - j - 1;
            int s0 = smp[i - order + j];
            int s1 = smp[i - order + j + 1];
            p0 += coefs[idx0] * s0;
            p1 += coefs[idx0] * s1;
            if (j + 1 < order) {
                p0 += coefs[idx1] * s1;
                p1 += coefs[idx1] * smp[i - order + j + 2];
            }
        }
    }
    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
}
}
