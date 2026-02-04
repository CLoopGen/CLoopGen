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
    for (i = -len, j = len - 1; i < 0; i++, j--) {
        int32_t local_s0 = src0[i];
        int32_t local_s1 = src1[j];
        int32_t local_wi = win[i];
        int32_t local_wj = win[j];
        int64_t prod1 = (int64_t)local_s0 * local_wj;
        int64_t prod2 = (int64_t)local_s1 * local_wi;
        int64_t sum1 = prod1 - prod2 + 1073741824;
        int64_t sum2 = prod1 + prod2 + 1073741824;
        dst[i] = (int32_t)(sum1 >> 31);
        dst[j] = (int32_t)(sum2 >> 31);
    }
}
