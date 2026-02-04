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
    // Variant 1: Consecutive memory access (unit stride)
    // Instead of strided access, process consecutive elements in memory
    uint16_t *base = src;
    for (i = 0; i < 8; i++) {
        (((av_alias64 *)(((uint64_t *)(base + i * 8)) + 0))->u64 = (a));
        (((av_alias64 *)(((uint64_t *)(base + i * 8)) + 1))->u64 = (a));
    }
}
