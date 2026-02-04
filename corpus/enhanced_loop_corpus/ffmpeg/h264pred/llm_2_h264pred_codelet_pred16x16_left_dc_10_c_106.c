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
    // Variant 1: Consecutive memory access with unrolled writes to adjacent locations
    uint16_t *base = src;
    for (i = 0; i < 16; i++) {
        av_alias64 *a = (av_alias64*)(base);
        a[0].u64 = dcsplat;
        a[1].u64 = dcsplat;
        a[2].u64 = dcsplat;
        a[3].u64 = dcsplat;
        base += 16; // Move to next row after writing 8 uint16_t elements (16 bytes)
    }
}
