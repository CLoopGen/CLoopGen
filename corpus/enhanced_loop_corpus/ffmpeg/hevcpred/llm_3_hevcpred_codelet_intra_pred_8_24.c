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
    // Variant 2: Strided memory access with increasing stride over iterations
    // Access pattern jumps by a fixed stride greater than element size, simulating non-unit strided access.
    // Here, stride is set to 8, meaning every other 4-byte slot is updated, skipping one in between.
    const int stride = 8;
    int count = 0;
    for (i = 0; i < (2 * size) && count < (2 * size) / 4; i += stride, count++) {
        ((union unaligned_32 *)(top + i))->l = pix;
    }
}
