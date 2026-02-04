#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint8_t *src;
extern int angle;
extern  uint8_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    if (fact) {
        uint8_t *ref1 = &ref[idx + 1];
        uint8_t *ref2 = &ref[idx + 2];
        for (y = 0; y < size; y++) {
            ptrdiff_t src_offset = x + stride * y;
            ptrdiff_t ref1_offset = y;
            src[src_offset] = ((32 - fact) * ref1[ref1_offset] + fact * ref2[ref1_offset] + 16) >> 5;
        }
    } else {
        uint8_t *ref_src = &ref[idx + 1];
        for (y = 0; y < size; y++) {
            src[x + stride * y] = ref_src[y];
        }
    }
}
}
