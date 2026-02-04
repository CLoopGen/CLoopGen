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
for (y = 0; y < size; y += 2) {
    int idx1 = ((y + 1) * angle) >> 5;
    int fact1 = ((y + 1) * angle) & 31;
    int idx2 = ((y + 2) * angle) >> 5;
    int fact2 = ((y + 2) * angle) & 31;
    if (fact1) {
        for (x = 0; x < size; x += 4) {
            src[(x)   + stride * y] = ((32 - fact1) * ref[x + idx1 + 1] + fact1 * ref[x + idx1 + 2] + 16) >> 5;
            src[(x+1) + stride * y] = ((32 - fact1) * ref[x+1+idx1 + 1] + fact1 * ref[x+1+idx1 + 2] + 16) >> 5;
            src[(x+2) + stride * y] = ((32 - fact1) * ref[x+2+idx1 + 1] + fact1 * ref[x+2+idx1 + 2] + 16) >> 5;
            src[(x+3) + stride * y] = ((32 - fact1) * ref[x+3+idx1 + 1] + fact1 * ref[x+3+idx1 + 2] + 16) >> 5;
        }
    } else {
        for (x = 0; x < size; x += 4)
            ((((union unaligned_32 *)(&src[(x) + stride * y]))->l) = ((((const union unaligned_32 *)(&ref[x + idx1 + 1]))->l)));
    }
    if (y + 1 < size) {
        if (fact2) {
            for (x = 0; x < size; x += 4) {
                src[(x)   + stride * (y+1)] = ((32 - fact2) * ref[x + idx2 + 1] + fact2 * ref[x + idx2 + 2] + 16) >> 5;
                src[(x+1) + stride * (y+1)] = ((32 - fact2) * ref[x+1+idx2 + 1] + fact2 * ref[x+1+idx2 + 2] + 16) >> 5;
                src[(x+2) + stride * (y+1)] = ((32 - fact2) * ref[x+2+idx2 + 1] + fact2 * ref[x+2+idx2 + 2] + 16) >> 5;
                src[(x+3) + stride * (y+1)] = ((32 - fact2) * ref[x+3+idx2 + 1] + fact2 * ref[x+3+idx2 + 2] + 16) >> 5;
            }
        } else {
            for (x = 0; x < size; x += 4)
                ((((union unaligned_32 *)(&src[(x) + stride * (y+1)]))->l) = ((((const union unaligned_32 *)(&ref[x + idx2 + 1]))->l)));
        }
    }
}
}
