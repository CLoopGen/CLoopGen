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
    for (i = 0; i < (32 - bottom_left_size); i += 8) {
        uint8_t *addr1 = left + 32 + bottom_left_size + i;
        uint8_t *addr2 = left + 32 + bottom_left_size + i + 4;
        ((union unaligned_32 *)addr1)->l = pix;
        if (i + 4 < (32 - bottom_left_size)) {
            ((union unaligned_32 *)addr2)->l = pix;
        }
    }
}
