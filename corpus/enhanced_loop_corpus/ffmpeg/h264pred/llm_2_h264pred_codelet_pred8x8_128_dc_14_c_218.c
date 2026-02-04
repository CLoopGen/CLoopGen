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
extern  uint64_t a;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (coalesced)
    // Instead of strided access, we assume data is laid out consecutively in memory
    // We remove stride dependency and access elements in a contiguous block
    uint16_t *base = src;
    for (i = 0; i < 8; i++) {
        uint64_t *aligned_ptr = (uint64_t*)(base + i * 4); // Each write uses 4 uint16_t = 8 bytes
        ((av_alias64*)(aligned_ptr + 0))->u64 = a;
        ((av_alias64*)(aligned_ptr + 1))->u64 = a;
    }
}
