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
    for (i = -len; i < 0; i++) {
        s0 = src0[i];
        wi = win[i];
        dst[i] = ((int64_t)s0 * wi + 1073741824) >> 31;
        if (i + len < len) {
            j = len - 1 - (i + len);
            s1 = src1[j];
            wj = win[j];
            dst[j] = ((int64_t)s1 * wj + 1073741824) >> 31;
        }
    }
}
