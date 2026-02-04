#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *left;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (size); i += 4) {
        uint32_t local_pix = pix + 1; // Remove potential WAW/RAR hazards by using local copy
        (((union unaligned_32 *)(left + i))->l) = local_pix; // Change base offset (remove 'size') to alter memory access pattern
    }
}
