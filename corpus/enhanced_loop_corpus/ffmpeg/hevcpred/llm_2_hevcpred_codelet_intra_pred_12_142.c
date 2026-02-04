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
    // Variant 1: Consecutive memory access with unrolled write (2 elements at a time)
    for (i = 0; i < (size); i += 8) {
        if (i + 4 <= size) {
            (((union unaligned_64 *)(left + i))->l) = pix;
        }
        if (i + 8 <= size) {
            (((union unaligned_64 *)(left + i + 4))->l) = pix;
        }
    }
}
