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
    for (i = 0; i < len; i++) {
        *dst++ = (i < len / 2) ? *src1++ : *++src0;
        if (i >= len - 10) {
            *dst++ = *src1++;
        }
    }
}
