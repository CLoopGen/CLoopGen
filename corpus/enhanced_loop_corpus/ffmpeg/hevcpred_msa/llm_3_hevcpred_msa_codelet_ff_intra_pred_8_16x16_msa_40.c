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
    // Variant 2: Strided memory access with stride of 8 (access every other 32-bit word, effectively writing every 8th byte)
    const int stride = 8;
    int limit = (size_max_y / stride) * stride; // Align to stride boundary
    for (i = 0; i < limit; i += stride) {
        (((union unaligned_32 *)(left + i))->l) = pix;
    }
}
