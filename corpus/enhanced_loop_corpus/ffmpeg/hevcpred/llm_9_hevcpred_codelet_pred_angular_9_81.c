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
for (y = 0; y < size; y += 2) {
    int idx0 = ((y + 1) * angle) >> 5;
    int fact0 = ((y + 1) * angle) & 31;
    int idx1 = ((y + 2) * angle) >> 5;
    int fact1 = ((y + 2) * angle) & 31;
    if (fact0) {
        for (x = 0; x < size; x += 4) {
            uint16_t r0 = ref[x + idx0 + 1], r1 = ref[x + idx0 + 2];
            src[(x) + stride * (y)] = ((32 - fact0) * r0 + fact0 * r1 + 16) >> 5;
            src[(x + 1) + stride * (y)] = ((32 - fact0) * ref[x + 1 + idx0 + 1] + fact0 * ref[x + 1 + idx0 + 2] + 16) >> 5;
            src[(x + 2) + stride * (y)] = ((32 - fact0) * ref[x + 2 + idx0 + 1] + fact0 * ref[x + 2 + idx0 + 2] + 16) >> 5;
            src[(x + 3) + stride * (y)] = ((32 - fact0) * ref[x + 3 + idx0 + 1] + fact0 * ref[x + 3 + idx0 + 2] + 16) >> 5;
        }
    } else {
        for (x = 0; x < size; x += 4)
            ((((union unaligned_64 *)(&src[(x) + stride * (y)]))->l) = ((((const union unaligned_64 *)(&ref[x + idx0 + 1]))->l)));
    }
    if (y + 1 < size) {
        if (fact1) {
            for (x = 0; x < size; x += 4) {
                src[(x) + stride * (y + 1)] = ((32 - fact1) * ref[x + idx1 + 1] + fact1 * ref[x + idx1 + 2] + 16) >> 5;
                src[(x + 1) + stride * (y + 1)] = ((32 - fact1) * ref[x + 1 + idx1 + 1] + fact1 * ref[x + 1 + idx1 + 2] + 16) >> 5;
                src[(x + 2) + stride * (y + 1)] = ((32 - fact1) * ref[x + 2 + idx1 + 1] + fact1 * ref[x + 2 + idx1 + 2] + 16) >> 5;
                src[(x + 3) + stride * (y + 1)] = ((32 - fact1) * ref[x + 3 + idx1 + 1] + fact1 * ref[x + 3 + idx1 + 2] + 16) >> 5;
            }
        } else {
            for (x = 0; x < size; x += 4)
                ((((union unaligned_64 *)(&src[(x) + stride * (y + 1)]))->l) = ((((const union unaligned_64 *)(&ref[x + idx1 + 1]))->l)));
        }
    }
}
}
