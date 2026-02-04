#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    ptrdiff_t offset = x;
    if (fact) {
        for (y = 0; y < size; y++) {
            ptrdiff_t src_offset = offset + stride * y;
            ptrdiff_t ref_offset1 = y + idx + 1;
            ptrdiff_t ref_offset2 = y + idx + 2;
            src[src_offset] = ((32 - fact) * ref[ref_offset1] + fact * ref[ref_offset2] + 16) >> 5;
        }
    } else {
        for (y = 0; y < size; y++)
            src[offset + stride * y] = ref[y + idx + 1];
    }
}
}
