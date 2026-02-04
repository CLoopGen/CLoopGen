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
    if (!fact) {
        for (x = 0; x < size; x += 4)
            ((((union unaligned_32 *)(&src[(x) + stride * (y)]))->l) = ((((const union unaligned_32 *)(&ref[x + idx + 1]))->l)));
    } else if (fact < 16) {
        for (x = 0; x < size; x++) {
            src[x + stride * y] = ((16 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 8) >> 4;
        }
    } else {
        for (x = 0; x < size; x += 4) {
            src[(x) + stride * (y)] = ((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
            src[(x + 1) + stride * (y)] = ((32 - fact) * ref[x + 1 + idx + 1] + fact * ref[x + 1 + idx + 2] + 16) >> 5;
            src[(x + 2) + stride * (y)] = ((32 - fact) * ref[x + 2 + idx + 1] + fact * ref[x + 2 + idx + 2] + 16) >> 5;
            src[(x + 3) + stride * (y)] = ((32 - fact) * ref[x + 3 + idx + 1] + fact * ref[x + 3 + idx + 2] + 16) >> 5;
        }
    }
}
}
