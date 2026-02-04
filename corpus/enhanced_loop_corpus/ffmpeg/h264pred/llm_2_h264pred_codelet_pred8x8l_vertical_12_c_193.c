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
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent elements directly
    uint64_t *base = (uint64_t *)(src + stride);
    for (int i = 0; i < 7; i++) {
        ((av_alias64*)&base[2*i + 0])->u64 = a;
        ((av_alias64*)&base[2*i + 1])->u64 = b;
    }
}
