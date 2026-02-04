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
    // Variant 1: Strided memory access with stride of 8 (access every other 4-byte chunk)
    for (x = 0; x <= size; x += 8) {
        if (x + 4 <= size) {  // Ensure we don't go out of bounds when accessing x+4
            (((union unaligned_32 *)(&ref_tmp[x]))->l) = ((((const union unaligned_32 *)(&top[x - 1]))->l));
            (((union unaligned_32 *)(&ref_tmp[x + 4]))->l) = ((((const union unaligned_32 *)(&top[x + 3]))->l));
        }
    }
}
