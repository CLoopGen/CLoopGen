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
for (i = order; i < len; i += 4) {
    int32_t p0 = 0, p1 = 0, p2 = 0, p3 = 0;
    int s0 = smp[i - order];
    int s1 = smp[i - order + 1];
    int s2 = smp[i - order + 2];
    int s3 = smp[i - order + 3];

    if (big) {
        for (int j = 0; j < order; j++) {
            int c = coefs[order - j - 1];
            p0 += c * s0;
            p1 += c * s1;
            p2 += c * s2;
            p3 += c * s3;

            if (j < order - 1) {
                s0 = smp[i - order + j + 1];
                s1 = smp[i - order + j + 2];
                s2 = smp[i - order + j + 3];
                s3 = smp[i - order + j + 4];
            }
        }
    } else {
        for (int j = 0; j < order; j++) {
            int c = coefs[order - j - 1];
            p0 += c * s0;
            p1 += c * s1;
            p2 += c * s2;
            p3 += c * s3;

            if (j < order - 1) {
                s0 = smp[i - order + j + 1];
                s1 = smp[i - order + j + 2];
                s2 = smp[i - order + j + 3];
                s3 = smp[i - order + j + 4];
            }
        }
    }

    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
    res[i + 2] = smp[i + 2] - (p2 >> shift);
    res[i + 3] = smp[i + 3] - (p3 >> shift);
}
}
