#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *top;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 8 (process every 4th 64-bit chunk, effectively skipping elements)
    for (x = 0; x <= size; x += 8) {
        if (x - 1 + 4 <= size) {  // Ensure source access is within bounds
            (((union unaligned_64 *)(&ref_tmp[x]))->l) = (((const union unaligned_64 *)(&top[x - 1]))->l);
        }
        if (x + 4 <= size && x + 3 <= size) {
            (((union unaligned_64 *)(&ref_tmp[x + 4]))->l) = (((const union unaligned_64 *)(&top[x + 3]))->l);
        }
    }
}
