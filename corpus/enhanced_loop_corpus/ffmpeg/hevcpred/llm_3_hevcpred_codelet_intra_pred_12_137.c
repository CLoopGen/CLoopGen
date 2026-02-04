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
extern int bottom_left_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride
    int stride = 4;
    for (i = 0; i < (size - bottom_left_size); i += stride * 2) {
        int index = size + bottom_left_size + i;
        (((union unaligned_64 *)(left + index))->l) = pix;
        // Simulate non-unit stride effect by skipping next potential write location
    }
}
