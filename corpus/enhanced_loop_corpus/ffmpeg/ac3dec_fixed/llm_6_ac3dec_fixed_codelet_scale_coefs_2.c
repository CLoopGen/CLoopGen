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
        int32_t temp0 = src[i] * mul;
        int32_t temp1 = src[i + 1] * mul;
        int32_t temp2 = src[i + 2] * mul;
        int32_t temp3 = src[i + 3] * mul;
        dst[i] = temp0;
        dst[i + 1] = temp1;
        dst[i + 2] = temp2;
        dst[i + 3] = temp3;
        int32_t temp4 = src[i + 4] * mul;
        int32_t temp5 = src[i + 5] * mul;
        int32_t temp6 = src[i + 6] * mul;
        int32_t temp7 = src[i + 7] * mul;
        dst[i + 4] = temp4;
        dst[i + 5] = temp5;
        dst[i + 6] = temp6;
        dst[i + 7] = temp7;
    }
}
