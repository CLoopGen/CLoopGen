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
    int s = smp[i - order];
    int32_t p0 = 0, p1 = 0;
    if (big) {
        for (int j = order; j >= 1; j--) {
            int c = coefs[j - 1];
            p0 += c * s;
            s = smp[i - j + 1];
            p1 += c * s;
        }
    } else {
        for (int j = order; j >= 1; j--) {
            int c = coefs[j - 1];
            p0 += c * s;
            s = smp[i - j + 1];
            p1 += c * s;
        }
    }
    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
}
}
