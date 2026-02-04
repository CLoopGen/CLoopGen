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
    // Variant 1: Strided memory access with stride of 8 instead of 4
    // This changes the access pattern to skip more elements, simulating a wider step
    for (i = 0; i < (size_max_y); i += 8) {
        if (i + 3 < size_max_y) {  // Safe bounds check for writing 4 bytes
            ((((union unaligned_32 *)(left + i))->l) = (pix));
        }
    }
}
