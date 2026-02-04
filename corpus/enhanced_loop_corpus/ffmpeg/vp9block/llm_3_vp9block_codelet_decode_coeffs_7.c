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
    // Variant 2: Strided memory access with increased stride
    // Access elements with a larger stride (every 4th byte), reducing total iterations
    const int stride = 4;
    for (n = 0; n < end_x; n += stride) {
        // Only update if current index is within bounds
        ((av_alias32 *)(&a[n]))->u32 = (uint32_t)a[n] * 16843009;
        // Optional: process second valid offset within safe bounds
        if (n + 2 < end_x) {
            ((av_alias32 *)(&a[n + 2]))->u32 = (uint32_t)a[n + 2] * 16843009;
        }
    }
}
