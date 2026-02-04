#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int size;
extern int x;
extern  uint8_t *top;
extern uint8_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive forward byte-wise access unrolled to process 4 bytes at a time via direct indexing
    for (x = 0; x <= size - 3; x += 4) {
        ref_tmp[x + 0] = top[(x - 1) + 0];
        ref_tmp[x + 1] = top[(x - 1) + 1];
        ref_tmp[x + 2] = top[(x - 1) + 2];
        ref_tmp[x + 3] = top[(x - 1) + 3];
    }
    // Handle remaining bytes if size is not multiple of 4
    for (; x <= size; x++) {
        if (x - 1 >= 0) {
            ref_tmp[x] = top[x - 1];
        }
    }
}
