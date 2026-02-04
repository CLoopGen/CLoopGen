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
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        uint64_t val0 = dc0splat;
        uint64_t val1 = dc1splat;
        for (int j = 0; j < 2; j++) {
            (((av_alias64 *)(((uint64_t *)(src + (i * 2 + j) * stride)) + 0))->u64 = val0);
            (((av_alias64 *)(((uint64_t *)(src + (i * 2 + j) * stride)) + 1))->u64 = val1);
        }
    }
}
