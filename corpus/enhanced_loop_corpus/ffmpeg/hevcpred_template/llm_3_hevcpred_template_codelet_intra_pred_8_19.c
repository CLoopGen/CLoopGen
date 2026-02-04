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
    // Variant 2: Strided memory access — write every 8th byte instead of every 4th, doubling the stride
    for (i = 0; i < (2 * size); i += 8) {
        (((union unaligned_32 *)(top + i))->l) = pix;
    }
}
