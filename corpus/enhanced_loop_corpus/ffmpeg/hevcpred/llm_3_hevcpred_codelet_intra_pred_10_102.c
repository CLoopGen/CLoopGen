#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern uint16_t *left;
extern int size_max_y;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every 8th element (larger stride)
    const int stride = 8;
    for (i = 0; i < (size_max_y); i += stride) {
        if (i % 8 == 0) {  // Ensure alignment condition mimicry
            ((union unaligned_64 *)(left + i))->l = pix;
        }
    }
}
