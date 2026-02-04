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
for (i = 0; i < len; i += 8) {
    int idx0 = i;
    int idx1 = i + 1;
    int idx2 = i + 2;
    int idx3 = i + 3;
    int idx4 = i + 4;
    int idx5 = i + 5;
    int idx6 = i + 6;
    int idx7 = i + 7;
    dst[idx0] = src[idx0] * mul;
    dst[idx1] = src[idx1] * mul;
    dst[idx2] = src[idx2] * mul;
    dst[idx3] = src[idx3] * mul;
    dst[idx4] = src[idx4] * mul;
    dst[idx5] = src[idx5] * mul;
    dst[idx6] = src[idx6] * mul;
    dst[idx7] = src[idx7] * mul;
}
}
