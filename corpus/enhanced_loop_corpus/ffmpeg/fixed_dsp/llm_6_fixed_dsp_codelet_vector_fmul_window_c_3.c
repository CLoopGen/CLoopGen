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
        s0 = src0[i];
        wi = win[i];
        s1 = src1[j];
        wj = win[j];
        int64_t temp1 = (int64_t)s0 * wj - (int64_t)s1 * wi + 1073741824;
        int64_t temp2 = (int64_t)s0 * wi + (int64_t)s1 * wj + 1073741824;
        dst[i] = temp1 >> 31;
        dst[j] = temp2 >> 31;
    }
}
