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
extern  uint64_t a;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i += 2) {
        uint64_t offset1 = (a + i) & 0xFFFFFFFFFFFFULL;
        uint64_t offset2 = (a - i) ^ 0x123456789ABCULL;
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = offset1;
        ((av_alias64 *)(((uint64_t *)(src + (i+1) * stride)) + 0))->u64 = offset2;
    }
}
