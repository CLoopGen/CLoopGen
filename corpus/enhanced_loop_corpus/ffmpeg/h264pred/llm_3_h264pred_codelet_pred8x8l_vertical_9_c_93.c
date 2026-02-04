#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern int y;
extern uint16_t *src;
extern int stride;
extern uint64_t a;
extern uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with increased stride step (access every other row, simulating sparse pattern)
    for (y = 1; y < 8; y += 2) {  // Stride of 2 in loop index
        uint64_t *row_ptr = (uint64_t *)(src + y * stride);
        ((av_alias64 *)(row_ptr + 0))->u64 = a;
        ((av_alias64 *)(row_ptr + 1))->u64 = b;
    }
}
