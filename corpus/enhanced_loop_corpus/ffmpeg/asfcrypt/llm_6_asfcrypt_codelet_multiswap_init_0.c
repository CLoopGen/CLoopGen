#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t keybuf[48];
extern uint32_t keys[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp;
    for (i = 0; i < 12; i++) {
        temp = ((const union unaligned_32 *)(keybuf + (i << 2)))->l;
        keys[i] = temp | 1;
    }
}
