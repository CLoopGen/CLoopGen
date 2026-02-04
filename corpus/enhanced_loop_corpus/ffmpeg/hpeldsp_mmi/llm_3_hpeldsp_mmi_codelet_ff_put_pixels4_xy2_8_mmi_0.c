#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;
extern uint32_t l0;
extern uint32_t h0;
extern uint32_t l1;
extern uint32_t h1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **pixel_ptr = (uint8_t **)malloc(h * sizeof(uint8_t *));
    uint8_t **block_ptr = (uint8_t **)malloc(h * sizeof(uint8_t *));
    
    for (int idx = 0; idx < h; idx++) {
        pixel_ptr[idx] = pixels + idx * line_size;
        block_ptr[idx] = block + idx * line_size;
    }

    for (i = 0; i < h; i += 2) {
        uint32_t a = ((const union unaligned_32 *)(pixel_ptr[i]))->l;
        uint32_t b = ((const union unaligned_32 *)(pixel_ptr[i] + 1))->l;
        l1 = (a & 50529027UL) + (b & 50529027UL);
        h1 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        *((uint32_t *)block_ptr[i]) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);

        a = ((const union unaligned_32 *)(pixel_ptr[i+1]))->l;
        b = ((const union unaligned_32 *)(pixel_ptr[i+1] + 1))->l;
        l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
        h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        *((uint32_t *)block_ptr[i+1]) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    }

    free(pixel_ptr);
    free(block_ptr);
}
