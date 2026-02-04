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
    // Variant 2: Consecutive but reverse-order memory access from end to start
    for (i = (size - (size % 4)); i > 0; i -= 4)
        ((((union unaligned_32 *)(left + i - 4))->l) = (pix));
}
