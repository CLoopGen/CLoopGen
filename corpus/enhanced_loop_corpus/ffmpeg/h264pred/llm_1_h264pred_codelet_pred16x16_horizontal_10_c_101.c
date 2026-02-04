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
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = j + i * 4;
            const uint64_t a = ((src[-1 + idx * stride]) * 281479271743489ULL);
            (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 0))->u64 = (a));
            (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 1))->u64 = (a));
            (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 2))->u64 = (a));
            (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 3))->u64 = (a));
        }
    }
}
