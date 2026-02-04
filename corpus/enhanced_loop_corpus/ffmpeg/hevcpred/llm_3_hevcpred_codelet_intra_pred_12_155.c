#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write using byte-level pointer arithmetic to ensure dense, aligned-friendly writes
    uint8_t *byte_ptr = (uint8_t *)left;
    uint64_t *as_longs = (uint64_t *)byte_ptr;
    for (i = 0; i < (size / 4); ++i)
        as_longs[i] = pix;
}
