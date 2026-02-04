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
    // Variant 2: Strided access with transposed write indices
    uint16_t *base = src;
    ptrdiff_t offset_step = stride / sizeof(uint16_t);
    for (i = 0; i < 16; i++) {
        uint16_t *p0 = base + 0 * offset_step;
        uint16_t *p1 = base + 4 * offset_step;
        uint16_t *p2 = base + 8 * offset_step;
        uint16_t *p3 = base + 12 * offset_step;
        ((av_alias64 *)p0)->u64 = dcsplat;
        ((av_alias64 *)p1)->u64 = dcsplat;
        ((av_alias64 *)p2)->u64 = dcsplat;
        ((av_alias64 *)p3)->u64 = dcsplat;
        base += offset_step;
    }
}
