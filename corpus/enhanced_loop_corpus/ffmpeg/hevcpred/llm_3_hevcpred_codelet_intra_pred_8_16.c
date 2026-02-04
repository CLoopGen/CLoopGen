#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *left;
extern int size_max_y;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride to simulate non-contiguous pattern
    const int base_stride = 4;
    const int stride_multiplier = 2; // Access every 8 bytes instead of consecutive 4-byte chunks
    for (i = 0; i < size_max_y; i += base_stride * stride_multiplier)
        ((((union unaligned_32 *)(left + i))->l) = (pix));
}
