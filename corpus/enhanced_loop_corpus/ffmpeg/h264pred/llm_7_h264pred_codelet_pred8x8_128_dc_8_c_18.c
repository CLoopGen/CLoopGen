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
    uint32_t prev_a = a;
    for (i = 0; i < 8; i++) {
        uint32_t new_a = prev_a + 0x1010101;  // Create WAW and loop-carried dependency
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = prev_a);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = new_a);
        prev_a = new_a;  // Loop-carried dependence: current iteration depends on previous write
    }
}
