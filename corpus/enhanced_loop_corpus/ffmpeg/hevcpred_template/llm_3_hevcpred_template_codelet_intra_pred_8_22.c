#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every 8th byte (stride of 8), treating it as aligned 32-bit stores
    const int stride = 8;
    for (i = 0; i < (size - 3); i += stride) {
        ((((union unaligned_32 *)(top + i))->l) = (pix));
    }
}
