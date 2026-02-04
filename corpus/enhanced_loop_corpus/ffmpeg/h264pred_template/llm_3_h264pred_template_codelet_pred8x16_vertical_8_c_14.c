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

extern int i;
extern uint8_t *src;
extern int stride;
extern  uint32_t a;
extern  uint32_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed write pattern (interleaved a and b across iterations)
    uint8_t *base = src;
    int effective_stride = stride * 2; // Simulate wider stride for alternating effect
    for (i = 0; i < 16; i += 2) {
        // Interleave writes of a and b in strided locations
        ((av_alias32*)(void*)(base + i * stride + 0))->u32 = a;
        ((av_alias32*)(void*)(base + (i + 1) * stride + 4))->u32 = b;
        if (i + 1 < 16) {
            ((av_alias32*)(void*)(base + (i + 1) * stride + 0))->u32 = a;
            ((av_alias32*)(void*)(base + i * stride + 4))->u32 = b;
        }
    }
}
