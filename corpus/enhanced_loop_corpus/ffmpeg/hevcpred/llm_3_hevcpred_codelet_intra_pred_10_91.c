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
    // Variant 2: Strided memory access — write every other 64-bit location, effectively doubling the stride
    union unaligned_64 *ptr = (union unaligned_64 *)(top + size + top_right_size);
    for (i = 0; i < (size - top_right_size); i += 8) {  // Note: step by 8 in index to create strided access
        ptr[i / 4].l = pix;
    }
}
