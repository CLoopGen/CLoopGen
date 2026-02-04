#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *left;
extern int bottom_left_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (32 - bottom_left_size); i += 4) {
        if (i >= 8) {
            (((union unaligned_32 *)(left + 32 + bottom_left_size + i))->l) = pix;
        }
    }
}
