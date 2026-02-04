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
    int effective_order = big ? 32 : 8;

    for (int j = effective_order; j >= 1; j--) {
        if (j > order) continue;

        int c = coefs[j - 1];
        p0 += c * s;
        s = smp[i - j + 1];
        p1 += c * s;

        if (j <= 8 && !big) break;
    }

    res[i] = (p0 >> shift) > smp[i] ? 0 : smp[i] - (p0 >> shift);
    if (i + 1 < len) {
        res[i + 1] = (p1 >> shift) > smp[i + 1] ? 0 : smp[i + 1] - (p1 >> shift);
    } else {
        break;
    }
}
}
