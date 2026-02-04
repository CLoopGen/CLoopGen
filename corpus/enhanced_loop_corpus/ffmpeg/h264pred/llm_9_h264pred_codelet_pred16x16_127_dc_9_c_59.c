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
for (i = 0; i < 8; i++) {
    for (int j = 0; j < 2; j++) {
        uint64_t val = ((((1 << (9 - 1)) - 1) * 281479271743489ULL)) + (j * 256);
        (((av_alias64 *)(src + 0 + j*8))->u64 = val);
        (((av_alias64 *)(src + 4 + j*8))->u64 = val ^ 0xFFFFFFFF00000000ULL);
    }
    src += stride;
}
}
