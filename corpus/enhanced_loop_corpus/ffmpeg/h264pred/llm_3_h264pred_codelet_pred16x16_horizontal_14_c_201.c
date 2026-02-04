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
for (i = 0; i < 16; i++) {
    const int read_idx = (i * stride) - 1;
    const uint64_t a = (src[read_idx] * 281479271743489ULL);
    uint16_t *write_base = src + i * stride;
    for (int j = 0; j < 8; j += 2) {
        ((av_alias64 *)(write_base + j))->u64 = a;
    }
}
}
