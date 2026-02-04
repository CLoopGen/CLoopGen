#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *top;
extern int top_right_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (32 - top_right_size * 2); i += 8) {
        uint32_t temp_pix1 = pix;
        uint32_t temp_pix2 = pix << 1;
        ((((union unaligned_32 *)(top + 16 + top_right_size + i))->l) = temp_pix1);
        if (i + 4 < (32 - top_right_size * 2))
            ((((union unaligned_32 *)(top + 16 + top_right_size + i + 4))->l) = temp_pix2);
    }
}
