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
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 8 (access every 8th element in terms of uint16_t index)
    const int stride = 8;
    int limit = (2 * size) - (2 * size) % stride; // Align to stride
    for (i = 0; i < limit; i += stride) {
        (((union unaligned_64 *)(top + i))->l) = pix;
    }
    // Handle remaining elements if any
    for (; i < (2 * size); i += 4) {
        (((union unaligned_64 *)(top + i))->l) = pix;
    }
}
