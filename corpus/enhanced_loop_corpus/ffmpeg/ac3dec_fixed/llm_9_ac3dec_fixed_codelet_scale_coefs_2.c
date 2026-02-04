#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern  int32_t *src;
extern int len;
extern int i;
extern unsigned int mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 16) {
        dst[i] = src[i] * mul;
        dst[i + 1] = src[i + 1] * mul;
        dst[i + 2] = src[i + 2] * mul;
        dst[i + 3] = src[i + 3] * mul;
        dst[i + 4] = src[i + 4] * mul;
        dst[i + 5] = src[i + 5] * mul;
        dst[i + 6] = src[i + 6] * mul;
        dst[i + 7] = src[i + 7] * mul;
        if (i + 8 < len) dst[i + 8] = src[i + 8] * mul;
        if (i + 9 < len) dst[i + 9] = src[i + 9] * mul;
        if (i + 10 < len) dst[i + 10] = src[i + 10] * mul;
        if (i + 11 < len) dst[i + 11] = src[i + 11] * mul;
        if (i + 12 < len) dst[i + 12] = src[i + 12] * mul;
        if (i + 13 < len) dst[i + 13] = src[i + 13] * mul;
        if (i + 14 < len) dst[i + 14] = src[i + 14] * mul;
        if (i + 15 < len) dst[i + 15] = src[i + 15] * mul;
    }
}
