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



void loop() {
    for (i = order; i < len; i += 2) {
        int32_t p0 = 0, p1 = 0;
        if (big) {
            for (int j = 0; j < order; j++) {
                int idx = order - j - 1;
                int c = coefs[idx];
                p0 += c * smp[i - j];
                p1 += c * smp[i - j + 1];
            }
        } else {
            for (int j = 0; j < order; j++) {
                int idx = order - j - 1;
                int c = coefs[idx];
                p0 += c * smp[i - j];
                p1 += c * smp[i - j + 1];
            }
        }
        res[i] = smp[i] - (p0 >> shift);
        res[i + 1] = smp[i + 1] - (p1 >> shift);
    }
}
