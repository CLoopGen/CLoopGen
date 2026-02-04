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
    // Variant 2: Strided memory access with increasing step (every 8th element, then wrap to next base)
    const int stride = 8;
    int limit = size_max_y & ~7; // Align down to multiple of 8 for predictable access
    for (i = 0; i < limit; i += stride) {
        int idx = (i * 2) % size_max_y; // Non-consecutive, strided and wrapped index
        (((union unaligned_64 *)(left + idx))->l) = (pix);
    }
    // Handle remaining elements not covered by strided pattern
    for (; i < size_max_y; i += 4) {
        (((union unaligned_64 *)(left + i))->l) = (pix);
    }
}
