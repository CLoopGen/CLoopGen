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
    uint32_t prev = 0;
    for (y = 0; y < 256; y++) {
        uint32_t current = (((const union unaligned_32 *)(buf))->l) | 4278190080U;
        pal[y] = current ^ prev; // Introduce loop-carried dependence (WAW and RAW): current iteration depends on previous write
        prev = current;
        buf += 4;
    }
}
