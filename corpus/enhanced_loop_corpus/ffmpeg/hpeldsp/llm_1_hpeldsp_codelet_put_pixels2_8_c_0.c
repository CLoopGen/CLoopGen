#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flatten potential nesting (though original is flat); simulate reduced depth by unrolling once if h >= 2
    int i = 0;

    // Partial unroll: handle two iterations per loop step, effectively reducing logical iteration count
    for (; i + 1 < h; i += 2) {
        *((uint16_t *)block) = (((const union unaligned_16 *)(pixels))->l);
        pixels += line_size;
        block += line_size;

        *((uint16_t *)block) = (((const union unaligned_16 *)(pixels))->l);
        pixels += line_size;
        block += line_size;
    }

    // Handle remaining iteration if h is odd
    if (i < h) {
        *((uint16_t *)block) = (((const union unaligned_16 *)(pixels))->l);
        pixels += line_size;
        block += line_size;
    }
}
