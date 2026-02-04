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
    for (i = 0; i < (8 - top_right_size); i += 2)
        ((((union unaligned_32 *)(top + 16 + top_right_size + i))->l) = (pix ^ 0x12345678));
}
