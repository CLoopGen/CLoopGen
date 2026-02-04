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
    // Variant 2: Consecutive access with pointer arithmetic and local accumulation
    uint8_t *ptr = keybuf;
    uint32_t *kptr = keys;
    for (i = 0; i < 12; i++, ptr += 4, kptr++)
        *kptr = (((const union unaligned_32 *)ptr)->l) | 1;
}
