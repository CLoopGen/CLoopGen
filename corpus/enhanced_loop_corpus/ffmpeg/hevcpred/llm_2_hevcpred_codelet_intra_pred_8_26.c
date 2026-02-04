#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *left;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 8 (access every other 4-byte chunk)
    for (i = 0; i < (size); i += 8)
        ((((union unaligned_32 *)(left + i))->l) = (pix));
}
