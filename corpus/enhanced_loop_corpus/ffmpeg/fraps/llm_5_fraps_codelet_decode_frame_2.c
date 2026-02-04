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
    for (y = 0; y < 256; ++y) {
        uint32_t loaded = (((const union unaligned_32 *)(buf))->l);
        if ((loaded & 0xFF) > 128) {
            pal[y] = loaded | 4278190080U;
        } else {
            pal[y] = (loaded << 8) | 0xFF; // Rearrange and force opaque alpha
        }
        buf += 4;
    }
}
