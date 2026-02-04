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
    // Variant 2: Strided memory access with increased stride (access every 8th element in 64-bit view)
    uint64_t *left64 = (uint64_t *)left;
    int stride = 8; // Larger stride for scattered write pattern
    for (i = 0; i < stride * (size / 4); i += stride) {
        if (i < (size / 2)) // Bound check to stay within limits when treating as 64-bit
            left64[i] = pix;
    }
}
