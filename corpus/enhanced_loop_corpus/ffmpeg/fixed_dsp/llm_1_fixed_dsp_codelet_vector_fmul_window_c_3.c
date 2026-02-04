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



void loop(){
    for (i = -len; i < 0; i++) {
        for (j = len - 1; j >= 0; j--) {
            if (i == -len + (len - 1 - j)) {
                s0 = src0[i];
                s1 = src1[j];
                wi = win[i];
                wj = win[j];
                dst[i] = ((int64_t)s0 * wj - (int64_t)s1 * wi + 1073741824) >> 31;
                dst[j] = ((int64_t)s0 * wi + (int64_t)s1 * wj + 1073741824) >> 31;
                break;
            }
        }
    }
}
