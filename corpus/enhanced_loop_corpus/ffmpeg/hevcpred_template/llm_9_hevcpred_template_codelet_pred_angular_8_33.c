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
    for (int offset = 0; offset < 2; ++offset) {
        int current_y = y + offset;
        if (current_y >= size) break;
        int idx = ((current_y + 1) * angle) >> 5;
        int fact = ((current_y + 1) * angle) & 31;
        if (fact) {
            for (x = 0; x < size; x++) {
                int val = ((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
                src[x + stride * current_y] = val;
            }
        } else {
            for (x = 0; x < size; x += 4) {
                (((union unaligned_32 *)(&src[(x) + stride * current_y]))->l) = 
                    (((const union unaligned_32 *)(&ref[x + idx + 1]))->l);
            }
        }
    }
}
}
