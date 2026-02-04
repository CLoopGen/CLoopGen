#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern  int32_t *src0;
extern  int32_t *src1;
extern  int32_t *win;
extern int len;
extern int32_t s0;
extern int32_t s1;
extern int32_t wi;
extern int32_t wj;
extern int32_t i;
extern int32_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int step = 2;
    for (i = -len, j = len - 1; i < 0 && j > i; i += step, j -= step) {
        s0 = src0[i];
        s1 = src1[j];
        wi = win[i];
        wj = win[j];

        int64_t term1 = (int64_t)s0 * wj - (int64_t)s1 * wi + 1073741824;
        int64_t term2 = (int64_t)s0 * wi + (int64_t)s1 * wj + 1073741824;

        dst[i] = term1 >> 31;
        dst[j] = term2 >> 31;

        // Unroll factor of 2 with safety checks
        if (i + 1 < 0 && j - 1 > i + 1) {
            s0 = src0[i + 1];
            s1 = src1[j - 1];
            wi = win[i + 1];
            wj = win[j - 1];

            dst[i + 1] = ((int64_t)s0 * wj - (int64_t)s1 * wi + 1073741824) >> 31;
            dst[j - 1] = ((int64_t)s0 * wi + (int64_t)s1 * wj + 1073741824) >> 31;
        }
    }
}
