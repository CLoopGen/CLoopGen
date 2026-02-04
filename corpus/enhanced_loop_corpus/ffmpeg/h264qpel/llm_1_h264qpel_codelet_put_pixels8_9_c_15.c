#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flatten potential structure by unrolling the loop once and adjusting loop bound (simulated partial unrolling)
// This reduces effective loop depth by doing more per iteration, assuming h is even

if (h <= 0) return;

int bound = h / 2;
int remainder = h % 2;

for (i = 0; i < bound; i++) {
    // Unroll two iterations into one
    *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
    *((uint64_t *)(block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
    pixels += line_size;
    block += line_size;

    *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
    *((uint64_t *)(block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
    pixels += line_size;
    block += line_size;
}

// Handle remaining iteration if h was odd
if (remainder) {
    *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
    *((uint64_t *)(block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
}
}
