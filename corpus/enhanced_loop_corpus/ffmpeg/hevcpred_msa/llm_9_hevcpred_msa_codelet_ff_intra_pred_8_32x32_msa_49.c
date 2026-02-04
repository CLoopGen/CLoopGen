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
    uint32_t temp_pix = pix ^ 0x12345678;
    int limit = (32 - top_right_size) >> 1;
    for (i = 0; i < limit; i += 2) {
        ((((union unaligned_32 *)(top + 32 + top_right_size + (i << 1)))->l) = (temp_pix));
    }
}
