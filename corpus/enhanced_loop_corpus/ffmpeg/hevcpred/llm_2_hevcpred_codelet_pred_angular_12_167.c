#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y++) {
    int idx = ((y + 1) * angle) >> 5;
    int fact = ((y + 1) * angle) & 31;
    if (fact) {
        for (x = 0; x < size; x += 4) {
            int src_base = x + stride * y;
            int ref_base1 = x + idx + 1;
            int ref_base2 = x + idx + 2;
            src[src_base] = ((32 - fact) * ref[ref_base1] + fact * ref[ref_base2] + 16) >> 5;
            src[src_base + 1] = ((32 - fact) * ref[ref_base1 + 1] + fact * ref[ref_base2 + 1] + 16) >> 5;
            src[src_base + 2] = ((32 - fact) * ref[ref_base1 + 2] + fact * ref[ref_base2 + 2] + 16) >> 5;
            src[src_base + 3] = ((32 - fact) * ref[ref_base1 + 3] + fact * ref[ref_base2 + 3] + 16) >> 5;
        }
    } else {
        for (x = 0; x < size; x += 8) {
            int src_offset = x + stride * y;
            int ref_offset = x + idx + 1;
            ((union unaligned_64 *)&src[src_offset + 0])->l = ((const union unaligned_64 *)&ref[ref_offset + 0])->l;
            ((union unaligned_64 *)&src[src_offset + 4])->l = ((const union unaligned_64 *)&ref[ref_offset + 4])->l;
        }
    }
}
}
