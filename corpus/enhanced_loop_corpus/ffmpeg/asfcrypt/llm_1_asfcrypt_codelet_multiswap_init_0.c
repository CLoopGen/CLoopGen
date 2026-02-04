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
    for (i = 0; i < 3; i++) {
        for (int k = 0; k < 4; k++) {
            int index = i * 4 + k;
            keys[index] = (((const union unaligned_32 *)(keybuf + (index << 2)))->l) | 1;
        }
    }
}
