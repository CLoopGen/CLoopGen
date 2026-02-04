#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed step
    for (i = 1; i <= 4; i++) {
        int32_t *src1 = &p[i0 + i];
        int32_t *dst1 = &p[i0 - i];
        int32_t *src2 = &p[i1 - i - 1];
        int32_t *dst2 = &p[i1 + i - 1];
        *dst1 = *src1;
        *dst2 = *src2;
    }
}
