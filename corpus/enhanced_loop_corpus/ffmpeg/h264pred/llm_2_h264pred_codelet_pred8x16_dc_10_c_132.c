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
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (flatten strided access into contiguous)
    uint16_t *base = src;
    for (i = 0; i < 4; i++) {
        uint16_t *row = base + i * 2;  // Assume stride of 2 elements for consecutive layout
        ((av_alias64*)(row + 0))->u64 = dc0splat;
        ((av_alias64*)(row + 1))->u64 = dc1splat;
    }
}
