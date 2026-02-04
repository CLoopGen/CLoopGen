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
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of writing computed values immediately, accumulate and write in larger chunks.
    // Here we process 8 elements at a time but access them consecutively and unroll the pattern.
    for (n = 0; n < end_x; n += 8) {
        av_alias32 *p = (av_alias32*)(&a[n]);
        p[0].u32 = a[n + 0] * 16843009U;
        p[1].u32 = a[n + 1] * 16843009U;
        p[2].u32 = a[n + 2] * 16843009U;
        p[3].u32 = a[n + 3] * 16843009U;
    }
}
