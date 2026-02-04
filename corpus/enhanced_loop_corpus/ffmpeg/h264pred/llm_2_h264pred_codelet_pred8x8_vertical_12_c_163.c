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

extern int i;
extern uint16_t *src;
extern int stride;
extern  uint64_t a;
extern  uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (coalesced)
    // Instead of strided access, process consecutive elements in memory
    // Assume src is aligned and large enough to allow linear traversal
    uint64_t *src64 = (uint64_t *)src;
    for (i = 0; i < 8; i++) {
        (((av_alias64 *)(src64 + 2 * i + 0))->u64 = (a));
        (((av_alias64 *)(src64 + 2 * i + 1))->u64 = (b));
    }
}
