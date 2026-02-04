#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        const uint8_t* src_pixel = pixels;
        uint8_t* dst_block = block;

        if (src_pixel != NULL && dst_block != NULL) {
            *((uint64_t *)dst_block) = (((const union unaligned_64 *)src_pixel)->l);
            *((uint64_t *)(dst_block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(src_pixel + 4 * sizeof(uint16_t)))->l);
        }

        pixels += line_size;
        block += line_size;
    }
}
