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
extern int i;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed write pattern across iterations
    uint16_t *base_src = src;
    for (i = 0; i < 16; i++) {
        // Access elements in a strided manner across multiple rows for better cache utilization
        int offset = (i % 4) * 4; // Cycle through 0, 4, 8, 12 every 4 iterations
        ((av_alias64*)(base_src + offset))->u64 = (((1 << (10 - 1)) + 0) * 281479271743489ULL);
        base_src += stride / sizeof(uint16_t); // Move to next row in stride units
    }
}
