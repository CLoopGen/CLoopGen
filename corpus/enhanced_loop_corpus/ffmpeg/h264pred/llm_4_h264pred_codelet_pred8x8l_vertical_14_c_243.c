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

extern int y;
extern uint16_t *src;
extern int stride;
extern uint64_t a;
extern uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < 8; y++) {
        if (y % 2 == 0) {
            (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 0))->u64 = (a));
        } else {
            (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 1))->u64 = (b));
        }
    }
}
