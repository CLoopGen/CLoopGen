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
    for (y = 0; y < 512; y += 2) {
        uint32_t val1 = (((const union unaligned_32 *)(buf))->l) | 4278190080U;
        uint32_t val2 = (((const union unaligned_32 *)(buf + 4))->l) | 4278190080U;
        pal[y] = val1;
        if (y + 1 < 256) pal[y + 1] = val2;
        buf += 8;
    }
}
