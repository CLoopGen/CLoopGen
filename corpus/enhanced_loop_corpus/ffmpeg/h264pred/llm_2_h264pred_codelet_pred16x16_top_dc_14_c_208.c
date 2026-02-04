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
    // Variant 1: Consecutive memory access with sequential writes
    uint64_t *src64 = (uint64_t *)src;
    for (i = 0; i < 16; i++) {
        src64[0] = dcsplat;
        src64[1] = dcsplat;
        src64[2] = dcsplat;
        src64[3] = dcsplat;
        src64 += stride / sizeof(uint64_t);
    }
}
