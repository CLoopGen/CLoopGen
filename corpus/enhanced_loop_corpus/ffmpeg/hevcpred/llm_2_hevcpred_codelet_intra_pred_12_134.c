#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern int top_right_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with sequential write pattern
    uint64_t *base_ptr = (uint64_t *)(top + size + top_right_size);
    for (i = 0; i < (size - top_right_size); i += 4) {
        base_ptr[i / 4] = pix;
    }
}
