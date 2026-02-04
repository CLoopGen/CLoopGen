#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int csize;
extern int32_t *src0;
extern int32_t *src1;
extern int32_t *src2;
extern int32_t i0;
extern int32_t i1;
extern int32_t i2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < csize; i++) {
    if (i > csize / 2) {
        i1 = *src0 - (*src2 + *src1 >> 2);
        i0 = i1 + *src2;
        i2 = i1 + *src1;
    } else {
        i1 = *src0;
        i0 = i1;
        i2 = *src1;
    }
    *src0++ = i0;
    *src1++ = i1;
    *src2++ = i2;
}
}
