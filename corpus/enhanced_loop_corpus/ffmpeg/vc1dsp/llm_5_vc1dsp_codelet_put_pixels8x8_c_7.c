#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        const uint8_t* src = pixels;
        uint8_t* dst = block;

        if (i >= 4) {
            (*(uint32_t *)(dst)) = ((((const union unaligned_32 *)(src))->l));
        } else {
            (*(uint32_t *)(dst + 4)) = ((((const union unaligned_32 *)(src + 4))->l));
        }

        pixels += line_size;
        block += line_size;
    }
}
