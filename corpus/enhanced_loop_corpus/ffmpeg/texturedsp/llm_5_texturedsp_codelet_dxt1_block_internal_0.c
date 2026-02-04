#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern uint32_t colors[4];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        uint32_t pixel = colors[code & 3];
        code >>= 2;
        if (x >= y) {
            ((((union unaligned_32 *)(dst + x * 4))->l) = (pixel));
        } else {
            ((((union unaligned_32 *)(dst + x * 4))->l) = (colors[0]));
        }
    }
    dst += stride;
}
}
