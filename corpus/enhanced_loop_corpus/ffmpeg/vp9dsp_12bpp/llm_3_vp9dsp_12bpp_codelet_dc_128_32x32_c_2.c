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
    // Variant 2: Strided memory access with transposed indexing
    // Access memory in a column-major (strided across rows) fashion instead of row-wise.
    // Simulates processing along vertical dimensions (e.g., image column transformation).
    // We still perform 32 iterations but now each iteration processes one "column" element across multiple rows.
    uint16_t *base = dst;
    for (y = 0; y < 32; y++) {
        for (int row = 0; row < 8; row++) {
            uint16_t *target = base + row * (stride / sizeof(uint16_t)) + y * 4;
            ((av_alias64 *)target)->u64 = val;
        }
        // After processing 8 rows at offset y*4, advance logically to next group
        if ((y & 7) == 7) {  // Every 8 iterations, simulate block progression
            base += 32;  // Move horizontal block forward by 32 uint16_t (64 bytes)
        }
    }
}
