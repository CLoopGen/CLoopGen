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
    // Variant 2: Strided access with reversed iteration and alternating stride pattern
    ptrdiff_t effective_stride = stride * 2;
    for (i = 7; i >= 0; i--) {
        uint8_t *row = src + i * effective_stride;
        ((av_alias32*)((uint32_t*)row))[0].u32 = a;
        ((av_alias32*)((uint32_t*)row))[1].u32 = a;
    }
}
