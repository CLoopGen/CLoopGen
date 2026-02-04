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
extern uint8_t *dst;
extern uint32_t p4a;
extern uint32_t p4b;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_p4a = p4a;
    uint32_t local_p4b = p4b;
    uint8_t *temp_dst = dst;
    for (y = 0; y < 8; y++) {
        (((av_alias32 *)(temp_dst + 0))->u32 = local_p4a);
        (((av_alias32 *)(temp_dst + 4))->u32 = local_p4b);
        temp_dst += stride;
        // Eliminate loop-carried data dependencies entirely
        // All writes use loop-invariant values; only pointer advances
    }
    dst = temp_dst; // Update original dst only after loop
}
