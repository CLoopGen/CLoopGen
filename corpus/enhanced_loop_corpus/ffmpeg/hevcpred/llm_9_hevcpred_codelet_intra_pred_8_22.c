#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_pix1 = pix;
    uint32_t temp_pix2 = pix + 1;
    uint32_t temp_pix3 = pix + 2;
    uint32_t temp_pix4 = pix + 3;
    for (i = 0; i < size - 7; i += 8) {
        ((union unaligned_32 *)(top + i + 0))->l = temp_pix1;
        ((union unaligned_32 *)(top + i + 4))->l = temp_pix2;
        ((union unaligned_32 *)(top + i + 8))->l = temp_pix3;
        ((union unaligned_32 *)(top + i + 12))->l = temp_pix4;
    }
    // Handle remaining elements with reduced trip count and step
    for (; i < size; i += 4) {
        ((union unaligned_32 *)(top + i))->l = pix;
    }
}
