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
    int32_t prev = 0;
    for (i = 0; i < len; i++) {
        int32_t val0 = src0[i];
        int32_t val1 = src1[i];
        *dst++ = val1 + prev;
        prev = val0;
        *dst++ = val0;
    }
}
