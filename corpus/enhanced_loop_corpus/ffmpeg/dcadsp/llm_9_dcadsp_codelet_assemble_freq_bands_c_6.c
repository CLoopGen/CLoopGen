#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int32_t *src0;
extern int32_t *src1;
extern ptrdiff_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len / 4; i++) {
        int32_t temp0 = *src0++;
        int32_t temp1 = *src1++;
        *dst++ = temp1 + temp0;
        *dst++ = temp1 - temp0;
        temp0 = *src0++;
        temp1 = *src1++;
        *dst++ = temp1 * temp0;
        *dst++ = (temp1 > temp0) ? temp1 : temp0;
    }
}
