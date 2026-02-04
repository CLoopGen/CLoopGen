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
    uint32_t temp_colors[4];
    for (int i = 0; i < 4; i++) {
        temp_colors[i] = colors[i];
    }
    uint32_t local_code = code;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            uint32_t pixel = temp_colors[local_code & 3];
            (((union unaligned_32 *)(dst + x * 4))->l) = (pixel);
            local_code >>= 2;
        }
        dst += stride;
    }
}
