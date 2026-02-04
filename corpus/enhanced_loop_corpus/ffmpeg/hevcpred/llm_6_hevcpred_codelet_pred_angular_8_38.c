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
        uint32_t temp[4];
        for (x = 0; x < size; x += 4) {
            temp[0] = ((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
            temp[1] = ((32 - fact) * ref[x + 1 + idx + 1] + fact * ref[x + 1 + idx + 2] + 16) >> 5;
            temp[2] = ((32 - fact) * ref[x + 2 + idx + 1] + fact * ref[x + 2 + idx + 2] + 16) >> 5;
            temp[3] = ((32 - fact) * ref[x + 3 + idx + 1] + fact * ref[x + 3 + idx + 2] + 16) >> 5;
            src[(x) + stride * (y)] = temp[0];
            src[(x + 1) + stride * (y)] = temp[1];
            src[(x + 2) + stride * (y)] = temp[2];
            src[(x + 3) + stride * (y)] = temp[3];
        }
    } else {
        for (x = 0; x < size; x += 4)
            ((((union unaligned_32 *)(&src[(x) + stride * (y)]))->l) = ((((const union unaligned_32 *)(&ref[x + idx + 1]))->l)));
    }
}
}
