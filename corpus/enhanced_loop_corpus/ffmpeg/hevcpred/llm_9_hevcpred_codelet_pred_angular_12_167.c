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
    for (int offset = 0; offset < 2 && (y + offset) < size; ++offset) {
        int current_y = y + offset;
        int idx = ((current_y + 1) * angle) >> 5;
        int fact = ((current_y + 1) * angle) & 31;
        if (fact) {
            for (x = 0; x < size; x++) {
                int temp = ((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
                src[x + stride * current_y] = temp;
            }
        } else {
            for (x = 0; x < size; x += 4) {
                uint64_t val = ((const union unaligned_64 *)(&ref[x + idx + 1]))->l;
                ((union unaligned_64 *)(&src[x + stride * current_y]))->l = val;
            }
        }
    }
}
}
