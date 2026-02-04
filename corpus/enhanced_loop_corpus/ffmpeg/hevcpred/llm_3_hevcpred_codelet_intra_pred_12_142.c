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
    // Variant 2: Strided memory access with stride of 8 (access every 8th element in terms of uint16_t index)
    const int stride = 8;
    for (i = 0; i < (size); i += stride) {
        if (i + 4 <= size) {  // Ensure 4-byte alignment and buffer bounds
            (((union unaligned_64 *)(left + i))->l) = pix;
        }
    }
}
