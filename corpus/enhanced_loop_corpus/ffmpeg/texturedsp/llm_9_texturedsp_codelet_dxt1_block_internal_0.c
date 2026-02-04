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
for (y = 0; y < 2; y++) {
    for (x = 0; x < 4; x += 2) {
        uint32_t pixel1 = colors[code & 3];
        code >>= 2;
        uint32_t pixel2 = colors[code & 3];
        code >>= 2;
        ((((union unaligned_32 *)(dst + x * 4))->l) = (pixel1));
        ((((union unaligned_32 *)(dst + (x + 1) * 4))->l) = (pixel2));
    }
    dst += stride;
}
}
