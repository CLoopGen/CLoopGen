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
extern uint32_t p4c;
extern uint32_t p4d;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_a = p4a;
    uint32_t temp_b = p4b;
    uint32_t temp_c = p4c;
    uint32_t temp_d = p4d;
    for (y = 0; y < 16; y++) {
        (((av_alias32 *)(dst + 0))->u32 = temp_a);
        (((av_alias32 *)(dst + 4))->u32 = temp_b);
        (((av_alias32 *)(dst + 8))->u32 = temp_c);
        (((av_alias32 *)(dst + 12))->u32 = temp_d);
        temp_a ^= temp_b; // Introduce RAW dependency: temp_b used to update temp_a
        temp_c ^= temp_d; // Another intra-loop dependency
        dst += stride;
    }
}
