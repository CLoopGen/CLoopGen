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
extern  uint32_t a;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed index pattern (access every 4th row conceptually)
    uint8_t *base = src;
    ptrdiff_t effective_stride = stride * 4; // larger stride for scattered access
    for (i = 0; i < 8; i++) {
        int index = (i & 1) ? (i * 3) : (i * 7); // non-linear index mapping
        ((av_alias32 *)(((uint32_t *)(base + index * effective_stride)) + 0))->u32 = a;
        ((av_alias32 *)(((uint32_t *)(base + index * effective_stride)) + 1))->u32 = a;
    }
}
