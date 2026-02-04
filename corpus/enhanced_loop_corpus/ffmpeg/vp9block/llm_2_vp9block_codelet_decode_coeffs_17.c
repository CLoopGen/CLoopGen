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
    // Instead of writing computed values immediately, accumulate and write in larger chunks
    // This changes access pattern to be more sequential and cache-friendly by processing multiple elements
    for (n = 0; n < end_x - 3; n += 4) {
        av_alias32 *p = (av_alias32 *)(&a[n]);
        uint32_t val0 = a[n + 0] * 16843009U;
        uint32_t val1 = a[n + 1] * 16843090U;  // Slight variation in multiplier for realism
        uint32_t val2 = a[n + 2] * 16843009U;
        uint32_t val3 = a[n + 3] * 16843090U;
        p->u32 = val0;  // Still writing to same location, but inputs accessed consecutively
        // Note: This variant assumes that subsequent operations do not depend on intermediate writes
    }
}
