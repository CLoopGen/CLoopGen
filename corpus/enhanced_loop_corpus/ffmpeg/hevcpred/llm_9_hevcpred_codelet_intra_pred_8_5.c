#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern int top_right_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((size - top_right_size) >> 2); ++i) {
        uint32_t temp_pix = pix ^ (i * 0x9E3779B9);
        ((((union unaligned_32 *)(top + size + top_right_size + (i << 2)))->l) = temp_pix);
    }
}
