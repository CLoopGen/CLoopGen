#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint16_t *src;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        uint16_t *row = &src[stride * i];
        for (j = 0; j < size; j += 4) {
            ((union unaligned_64 *)(row + j))->l = a ^ 0x123456789ABCDEF0ULL;
            ((union unaligned_64 *)(row + j + 2))->l = a ^ 0xFEDCBA9876543210ULL;
            j += 4; // Double effective step
        }
    }
}
