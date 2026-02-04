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
    uint32_t temp1 = pix;
    uint32_t temp2 = pix + 1;
    for (i = 0; i < size / 2; i += 4) {
        ((union unaligned_32 *)(left + size + i))->l = temp1;
        ((union unaligned_32 *)(left + size + size - i - 4))->l = temp2;
    }
}
