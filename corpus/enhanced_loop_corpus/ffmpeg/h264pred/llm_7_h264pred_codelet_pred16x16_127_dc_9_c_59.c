#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern ptrdiff_t stride;
extern int i;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *temp_src[16];
    ptrdiff_t local_stride = stride;
    uint64_t values[16][4];
    uint64_t base_val = (((1 << (9 - 1)) - 1) * 281479271743489ULL);
    for (i = 0; i < 16; i++) {
        temp_src[i] = src + i * local_stride;
        values[i][0] = base_val;
        values[i][1] = base_val;
        values[i][2] = base_val;
        values[i][3] = base_val;
    }
    for (i = 0; i < 16; i++) {
        ((av_alias64*)(temp_src[i] + 0))->u64 = values[i][0];
        ((av_alias64*)(temp_src[i] + 4))->u64 = values[i][1];
        ((av_alias64*)(temp_src[i] + 8))->u64 = values[i][2];
        ((av_alias64*)(temp_src[i] + 12))->u64 = values[i][3];
    }
}
