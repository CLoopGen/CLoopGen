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
    // Variant 2: Strided memory access with step size of 8 (every other 4-byte chunk)
    // Alters access pattern from sequential to strided, touching non-consecutive memory locations
    for (n = 0; n < end_x; n += 8) {  // Stride of 8 bytes (two 4-byte segments apart)
        if (n + 4 < end_x) {
            ((av_alias32 *)(&a[n]))->u32 = (a[n] * 16843009);
            // Skip next 4-byte segment, next access at n+8
        }
    }
}
