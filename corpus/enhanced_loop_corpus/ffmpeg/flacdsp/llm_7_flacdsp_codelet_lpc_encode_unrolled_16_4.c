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
    int base_idx = i - order;
    if (big) {
        #pragma GCC unroll 32
        for (int j = 0; j < order; j++) {
            int idx = base_idx + j;
            int c = coefs[j];
            p0 += c * smp[idx];
            p1 += c * smp[idx + 1];
        }
    } else {
        #pragma GCC unroll 8
        for (int j = 0; j < order; j++) {
            int idx = base_idx + j;
            int c = coefs[j];
            p0 += c * smp[idx];
            p1 += c * smp[idx + 1];
        }
    }
    // Introduce WAR dependency by updating smp based on res (artificial but valid)
    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
    // Artificial WAW: overwrite same location conditionally (simulates redundant store)
    if ((i & 0x7) == 0) {
        res[i] = (res[i] + 1) & 0xFFFFFFF0;
    }
}
}
