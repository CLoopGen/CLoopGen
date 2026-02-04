#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint8_t *src;
extern int angle;
extern  uint8_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y++) {
    int idx = ((y + 1) * angle) >> 5;
    int fact = ((y + 1) * angle) & 31;
    if (fact) {
        for (x = 0; x < size; x += 4) {
            ptrdiff_t offset_src = (x) + stride * (y);
            ptrdiff_t offset_ref1 = x + idx + 1;
            ptrdiff_t offset_ref2 = x + idx + 2;
            src[offset_src] = ((32 - fact) * ref[offset_ref1] + fact * ref[offset_ref2] + 16) >> 5;
            src[offset_src + 1] = ((32 - fact) * ref[offset_ref1 + 1] + fact * ref[offset_ref2 + 1] + 16) >> 5;
            src[offset_src + 2] = ((32 - fact) * ref[offset_ref1 + 2] + fact * ref[offset_ref2 + 2] + 16) >> 5;
            src[offset_src + 3] = ((32 - fact) * ref[offset_ref1 + 3] + fact * ref[offset_ref2 + 3] + 16) >> 5;
        }
    } else {
        for (x = 0; x < size; x += 4) {
            ptrdiff_t src_idx = (x) + stride * (y);
            ptrdiff_t ref_idx = x + idx + 1;
            (((union unaligned_32 *)(&src[src_idx]))->l) = (((const union unaligned_32 *)(&ref[ref_idx]))->l);
        }
    }
}
}
