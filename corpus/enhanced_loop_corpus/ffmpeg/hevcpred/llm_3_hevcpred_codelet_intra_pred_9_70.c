#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using a temporary pointer to traverse the array without indexing
    uint16_t *ptr = top;
    for (i = 0; i < (size); i += 4, ptr += 4)
        ((((union unaligned_64 *)(ptr))->l) = (pix));
}
