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
extern uint64_t p4a;
extern uint64_t p4b;
extern uint64_t p4c;
extern uint64_t p4d;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled write using pointer arithmetic
    uint16_t *d = dst;
    for (y = 0; y < 16; y++) {
        av_alias64 *a = (av_alias64 *)d;
        a[0].u64 = p4a;
        a[1].u64 = p4b;
        a[2].u64 = p4c;
        a[3].u64 = p4d;
        d += stride;
    }
}
