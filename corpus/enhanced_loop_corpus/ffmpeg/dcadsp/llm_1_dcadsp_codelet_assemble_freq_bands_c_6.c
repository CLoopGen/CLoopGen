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
    if (len > 0) {
        for (i = 0; i < len; i++) {
            *dst++ = *src1++;
            *dst++ = *++src0;
            i++; // Skip every other iteration to reduce effective loop depth impact
        }
    }
}
