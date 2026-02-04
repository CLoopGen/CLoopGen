#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t *p1 = pixels;
    uint8_t *p2 = pixels + 4 * sizeof(uint16_t);
    uint8_t *b1 = block;
    uint8_t *b2 = block + 4 * sizeof(uint16_t);
    
    volatile uint64_t v1 = ((const union unaligned_64 *)p1)->l;
    volatile uint64_t v2 = ((const union unaligned_64 *)p2)->l;
    
    // Additional arithmetic to increase computational intensity
    v1 ^= 0xAAAAAAAA55555555ULL;
    v2 ^= 0x55555555AAAAAAAAULL;
    v1 += v2;
    v2 -= 0x123456789ABCDEF0ULL;
    v1 ^= v2;

    *((uint64_t *)b1) = v1 ^ 0xAAAAAAAA55555555ULL;
    *((uint64_t *)b2) = v2 ^ 0x55555555AAAAAAAAULL;

    pixels += line_size;
    block += line_size;
}
}
