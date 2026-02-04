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
    int j;
    for (i = 0; i < 32; i++) {
        uint64_t val = ((1ULL << 9) - 1) * 281479271743489ULL;
        for (j = 0; j < 2; j++) {
            (((av_alias64 *)(src + j * 8))->u64 = val);
            (((av_alias64 *)(src + j * 8 + 4))->u64 = val);
        }
        src += stride;
    }
}
