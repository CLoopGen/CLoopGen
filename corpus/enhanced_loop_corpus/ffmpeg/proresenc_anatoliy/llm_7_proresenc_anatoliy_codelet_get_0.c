#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *pixels;
extern int stride;
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        uint64_t val1 = ((const union unaligned_64 *)(pixels))->l;
        uint64_t val2 = ((const union unaligned_64 *)(pixels + 8))->l;
        ((union unaligned_64 *)(block + 8 - i % 9))->l = val1; // Introduce artificial WAW and WAR dependency with non-constant offset (still valid)
        ((union unaligned_64 *)(block + 4))->l = val2;
        pixels += stride;
        block += 8;
    }
}
