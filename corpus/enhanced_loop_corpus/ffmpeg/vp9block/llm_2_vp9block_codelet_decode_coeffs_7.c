#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling
    // Instead of accessing every element with stride 2, process two elements at a time consecutively
    for (n = 0; n < end_x - 1; n += 2) {
        av_alias32 *p1 = (av_alias32 *)(&a[n]);
        p1->u32 = (uint32_t)a[n] * 16843009;
        // Handle next consecutive byte in the same 32-bit chunk if alignment allows logical combination
        // Note: this assumes little-endian and that two adjacent bytes can be packed
        if (n + 1 < end_x) {
            av_alias32 *p2 = (av_alias32 *)(&a[n + 1]);
            p2->u32 = (uint32_t)a[n + 1] * 16843009;
        }
    }
    // Handle last element if end_x is odd
    if (n == end_x - 1) {
        ((av_alias32 *)(&a[n]))->u32 = (uint32_t)a[n] * 16843009;
    }
}
