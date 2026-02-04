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
    for (i = 0; i < 6; i++) {
        uint32_t val1 = (((const union unaligned_32 *)(keybuf + (i << 2)))->l) | 1;
        uint32_t val2 = (((const union unaligned_32 *)(keybuf + ((i + 6) << 2)))->l) | 1;
        keys[i] = val1 ^ (val1 >> 16);         // Additional arithmetic: XOR and shift
        keys[i + 6] = val2 ^ (val2 >> 16);
    }
}
