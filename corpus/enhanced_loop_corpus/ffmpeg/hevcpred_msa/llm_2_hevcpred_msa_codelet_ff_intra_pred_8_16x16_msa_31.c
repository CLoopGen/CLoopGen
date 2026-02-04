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
    for (i = 0; i < (16 - top_right_size); i += 4) {
        uint8_t *addr = top + 16 + top_right_size + i;
        ((union unaligned_32 *)addr)->l = pix;
    }
}
