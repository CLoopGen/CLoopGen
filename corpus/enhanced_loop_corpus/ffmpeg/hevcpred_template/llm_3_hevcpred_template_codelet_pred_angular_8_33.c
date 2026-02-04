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
    ptrdiff_t src_row_start = stride * y;
    const uint8_t* ref_row1 = ref + idx + 1;
    const uint8_t* ref_row2 = ref + idx + 2;
    if (fact) {
        for (x = 0; x < size; x += 4) {
            src[src_row_start + x] = ((32 - fact) * ref_row1[x] + fact * ref_row2[x] + 16) >> 5;
            src[src_row_start + x + 1] = ((32 - fact) * ref_row1[x + 1] + fact * ref_row2[x + 1] + 16) >> 5;
            src[src_row_start + x + 2] = ((32 - fact) * ref_row1[x + 2] + fact * ref_row2[x + 2] + 16) >> 5;
            src[src_row_start + x + 3] = ((32 - fact) * ref_row1[x + 3] + fact * ref_row2[x + 3] + 16) >> 5;
        }
    } else {
        for (x = 0; x < size; x += 4) {
            ptrdiff_t offset = src_row_start + x;
            ((((union unaligned_32 *)(&src[offset]))->l) = ((((const union unaligned_32 *)(&ref_row1[x]))->l)));
        }
    }
}
}
