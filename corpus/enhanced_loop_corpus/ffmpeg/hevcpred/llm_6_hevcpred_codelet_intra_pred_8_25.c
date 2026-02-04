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
    uint32_t temp_pix = pix;
    for (i = 0; i < (2 * size); i += 4) {
        (((union unaligned_32 *)(left + i))->l) = temp_pix;
        temp_pix ^= 0x80808080; // Introduce WAW and loop-carried dependency: each write depends on previous temp_pix
    }
}
