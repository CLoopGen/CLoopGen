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
    // Variant 1: Strided memory access with stride of 8 (access every 8th element in terms of uint16_t)
    // This changes the original sequential +4 increment to a wider stride, reducing total iterations
    // but accessing non-consecutive locations. The packing and aliasing are preserved.
    for (i = 0; i < (size); i += 8) {
        if (i + 4 < size) {  // Ensure we don't go out of bounds when writing 8 bytes (4x uint16_t)
            ((((union unaligned_64 *)(left + i))->l) = (pix));
        }
    }
}
