#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint8_t *src;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Transposed Iteration Order (column-blocked access)
    // Change iteration order to outer loop over j-tiles and inner over i, creating strided accumulation
    for (j = 0; j < size; j += 4) {
        for (i = 0; i < size; i++) {
            uint8_t *addr = &src[j + stride * i];
            ((union unaligned_32 *)addr)->l = a;
        }
    }
}
