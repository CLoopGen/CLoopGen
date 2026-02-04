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
    // Variant 1: Strided memory access with increased stride (access every 8th element instead of every 4th)
    for (i = 0; i < (size_max_y); i += 8)
        ((((union unaligned_64 *)(left + i))->l) = (pix));
}
