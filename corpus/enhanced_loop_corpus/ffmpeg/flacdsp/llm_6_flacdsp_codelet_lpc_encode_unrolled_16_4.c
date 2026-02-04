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
    int s0 = smp[i - order];
    int s1 = smp[i - order + 1];
    int32_t p0 = 0, p1 = 0;
    if (big) {
        for (int j = 0; j < order; j++) {
            int c = coefs[j];
            p0 += c * s0;
            p1 += c * s1;
            if (j < order - 1) {
                s0 = smp[i - order + j + 1];
                s1 = smp[i - order + j + 2];
            }
        }
    } else {
        for (int j = 0; j < order; j++) {
            int c = coefs[j];
            p0 += c * s0;
            p1 += c * s1;
            if (j < order - 1) {
                s0 = smp[i - order + j + 1];
                s1 = smp[i - order + j + 2];
            }
        }
    }
    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
}
}
