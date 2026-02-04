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
    for (y = 0; y < 128; y++) {
        uint32_t temp = (((const union unaligned_32 *)(buf))->l);
        temp = (temp & 0xFF) << 24 | (temp & 0xFF00) << 8 | (temp & 0xFF0000) >> 8 | (temp & 0xFF000000) >> 24; // Byte swap
        pal[y] = temp | 4278190080U;
        buf += 4;
    }
}
