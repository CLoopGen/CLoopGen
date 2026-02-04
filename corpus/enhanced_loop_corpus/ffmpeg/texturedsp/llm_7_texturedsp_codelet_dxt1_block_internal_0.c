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
    uint32_t scratchpad[16];
    uint32_t local_code = code;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            uint32_t pixel = colors[local_code & 3];
            scratchpad[y * 4 + x] = pixel;
            local_code >>= 2;
        }
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            (((union unaligned_32 *)(dst + x * 4))->l) = (scratchpad[y * 4 + x]);
        }
        dst += stride;
    }
}
