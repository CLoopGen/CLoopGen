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
extern uint16_t *dst;
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint16_t *base_dst = dst;
for (y = 0; y < 16; y++) {
    ptrdiff_t offset = y * stride;
    ((av_alias64 *)(base_dst + offset + 0))->u64 = val;
    ((av_alias64 *)(base_dst + offset + 4))->u64 = val;
    ((av_alias64 *)(base_dst + offset + 8))->u64 = val;
    ((av_alias64 *)(base_dst + offset + 12))->u64 = val;
}
}
