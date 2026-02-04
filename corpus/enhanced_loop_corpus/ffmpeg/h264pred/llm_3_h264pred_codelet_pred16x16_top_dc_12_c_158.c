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
extern uint64_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed indexing (access columns first)
    uint16_t *base_src = src;
    for (i = 0; i < 16; i++) {
        uint16_t *col0 = base_src + (i * stride / sizeof(uint16_t));
        ((av_alias64 *)col0)->u64 = dcsplat;

        uint16_t *col4 = col0 + 4;
        ((av_alias64 *)col4)->u64 = dcsplat;

        uint16_t *col8 = col0 + 8;
        ((av_alias64 *)col8)->u64 = dcsplat;

        uint16_t *col12 = col0 + 12;
        ((av_alias64 *)col12)->u64 = dcsplat;
    }
}
