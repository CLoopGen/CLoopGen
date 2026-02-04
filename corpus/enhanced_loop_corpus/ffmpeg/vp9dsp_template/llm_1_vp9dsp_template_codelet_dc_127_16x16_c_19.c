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
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int z = 0; z < 4; z++) {
    uint8_t* row_dst = dst + z * stride;
    ((av_alias32 *)(row_dst + 0))->u32 = val;
    ((av_alias32 *)(row_dst + 4))->u32 = val;
    ((av_alias32 *)(row_dst + 8))->u32 = val;
    ((av_alias32 *)(row_dst + 12))->u32 = val;
}
}
