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
    uint32_t temp1 = pix ^ 0x12345678;
    uint32_t temp2 = pix + 0xABCDEF01;
    for (i = 0; i < size; i += 4) {
        (((union unaligned_32 *)(left + i))->l) = (i % 8 == 0) ? temp1 : temp2;
    }
}
