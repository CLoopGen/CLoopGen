#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t *buf;
extern unsigned int y;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2 (simulating non-unit stride)
    for (y = 0; y < 256; y++) {
        pal[y] = (((const union unaligned_32 *)(buf + y * 8))->l) | 4278190080U;
    }
}
