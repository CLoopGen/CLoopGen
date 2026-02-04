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
        for (x = 0; x < size; x++) {
            src[x + stride * y] = ((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
        }
    } else {
        for (x = 0; x < size; x += 8) {
            if (x + 4 <= size) {
                ((((union unaligned_32 *)(&src[(x) + stride * (y)]))->l) = ((((const union unaligned_32 *)(&ref[x + idx + 1]))->l)));
                ((((union unaligned_32 *)(&src[(x+4) + stride * (y)]))->l) = ((((const union unaligned_32 *)(&ref[x+4 + idx + 1]))->l)));
            }
            for (int k = 0; k < 4 && x + 4 + k < size; k++) {
                src[x + 4 + k + stride * y] = ref[x + 4 + k + idx + 1];
            }
        }
    }
}
}
