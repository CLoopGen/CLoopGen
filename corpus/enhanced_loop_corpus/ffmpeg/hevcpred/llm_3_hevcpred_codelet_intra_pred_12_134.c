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
extern int top_right_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every other 64-bit word, stepping by 8 bytes each time
    uint64_t *ptr = (uint64_t *)(top + size + top_right_size);
    for (i = 0; i < (size - top_right_size); i += 8) {
        if ((i / 8) % 2 == 0) {  // Only write on even strides (simulate strided behavior)
            ((union unaligned_64 *)(ptr + (i / 8)))->l = pix;
        }
    }
}
