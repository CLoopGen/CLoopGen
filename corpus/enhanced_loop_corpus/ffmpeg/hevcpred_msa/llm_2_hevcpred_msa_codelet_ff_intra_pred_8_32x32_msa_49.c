#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *top;
extern int top_right_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using a pointer increment instead of indexing
    uint32_t *base = (uint32_t *)(top + 32 + top_right_size);
    for (i = 0; i < (32 - top_right_size); i += 4) {
        ((union unaligned_32 *)base)->l = pix;
        base++;
    }
}
