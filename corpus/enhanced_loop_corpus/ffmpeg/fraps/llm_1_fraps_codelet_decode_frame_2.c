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
    for (y = 0; y < 256; y += 4) {
        pal[y] = (((const union unaligned_32 *)(buf))->l) | 4278190080U;
        buf += 4;
        if (y + 1 < 256) {
            pal[y + 1] = (((const union unaligned_32 *)(buf))->l) | 4278190080U;
            buf += 4;
        }
        if (y + 2 < 256) {
            pal[y + 2] = (((const union unaligned_32 *)(buf))->l) | 4278190080U;
            buf += 4;
        }
        if (y + 3 < 256) {
            pal[y + 3] = (((const union unaligned_32 *)(buf))->l) | 4278190080U;
            buf += 4;
        }
    }
}
