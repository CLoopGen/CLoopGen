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
    uint32_t local_a[8]; // Eliminate loop-carried dependency by privatizing data
    for (i = 0; i < 8; i++) {
        local_a[i] = a ^ (i << 2); // Introduce variation independent of iteration order
    }
    for (i = 0; i < 8; i++) {
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = local_a[i];
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = local_a[i];
    }
}
