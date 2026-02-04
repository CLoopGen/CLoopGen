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

extern ptrdiff_t stride;
extern int i;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t prev_a = 0; // Introduce artificial loop-carried dependency (RAW)
    for (i = 0; i < 8; i++) {
        const uint8_t index_val = src[-1 + i * stride];
        const uint32_t a = (index_val * 16843009U) ^ prev_a; // Create RAW dependency on previous iteration
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = (a));
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = (a));
        prev_a = a; // Carry value forward, introducing loop-carried dependence
    }
}
