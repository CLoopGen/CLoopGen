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
extern uint64_t dc6splat;
extern uint64_t dc7splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 12; i < 14; i++) {
    uint64_t val6 = dc6splat;
    uint64_t val7 = dc7splat;
    for (int j = 0; j < 3; j++) {
        val6 ^= val7;
        val7 += 0x1234567812345678;
    }
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (val6));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (val7));
}
}
