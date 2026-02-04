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
    // Variant 2: Strided access with alternating pattern (increased stride step)
    uint8_t *ptr = src;
    ptrdiff_t effective_stride = stride * 2; // wider stride jump
    for (i = 0; i < 8; i++) {
        av_alias32 *p = (av_alias32*)(ptr + i * effective_stride);
        p->u32 = a;
        ((av_alias32*)((uint8_t*)p + sizeof(uint32_t)))->u32 = a;
    }
}
