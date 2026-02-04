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
        const int stride = 2;
        int base_idx = i - order + 1;

        if (big) {
            for (int j = order - 1; j >= 0; j -= stride) {
                int offset = j;
                int c = coefs[offset];
                p0 += c * smp[base_idx + offset];

                if (j > 0) {
                    p1 += c * smp[base_idx + offset - 1];
                }
            }
            for (int j = order - 2; j >= 0; j -= stride) {
                int offset = j;
                int c = coefs[offset];
                p1 += c * smp[base_idx + offset + 1];
            }
        } else {
            for (int j = order - 1; j >= 0; j--) {
                int offset = j;
                int c = coefs[offset];
                p0 += c * smp[base_idx + offset];
                p1 += c * smp[base_idx + offset + 1];
            }
        }

        res[i] = smp[i] - (p0 >> shift);
        res[i + 1] = smp[i + 1] - (p1 >> shift);
    }
}
