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
    // Variant 2: Consecutive (Forward) Array Traversal with Offset Base
    // Access elements consecutively but from the end to start (reverse order)
    // This changes spatial locality and access pattern
    for (i = csize - 1; i >= 0; i--) {
        int32_t *s0 = src0 + i;
        int32_t *s1 = src1 + i;
        int32_t *s2 = src2 + i;

        i1 = *s0 - (*s2 + *s1 >> 2);
        i0 = i1 + *s2;
        i2 = i1 + *s1;

        *s0 = i0;
        *s1 = i1;
        *s2 = i2;
    }
}
