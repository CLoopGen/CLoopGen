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

extern ptrdiff_t stride;
extern uint16_t *dst;
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed indexing
    // Access memory in a column-major-like fashion across multiple rows,
    // simulating a transpose operation over a 16x16 block.
    // We assume `dst` points to start of a larger buffer and stride is row step.
    uint16_t *base = dst;
    for (y = 0; y < 16; y++) {
        uint16_t *row = base + y; // Transpose index: now stepping down columns
        ((av_alias64 *)(row + 0))->u64 = val;
        ((av_alias64 *)(row + 4))->u64 = val;
        ((av_alias64 *)(row + 8))->u64 = val;
        ((av_alias64 *)(row + 12))->u64 = val;
    }
    // Finalize: advance original dst by full block height times stride
    dst = base + 16 * stride;
}
