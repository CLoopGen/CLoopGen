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
for (i = 0; i < 8; ++i) {
    const ptrdiff_t base_idx = i * stride;
    const uint64_t a = ((src[-1 + base_idx]) * 281479271743489ULL);
    uint16_t *write_ptr = src + base_idx;
    // Convert to consecutive 64-bit aligned write via union aliasing
    for (int j = 0; j < 2; ++j) {
        ((av_alias64 *)(write_ptr))[j].u64 = a;
    }
}
}
