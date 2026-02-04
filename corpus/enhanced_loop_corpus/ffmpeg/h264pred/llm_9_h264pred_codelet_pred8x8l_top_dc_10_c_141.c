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

extern uint16_t *src;
extern int stride;
extern  uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 2;
    for (y = 0; y < 4; y++) {
        uint64_t *src64_0 = (uint64_t*)(src);
        uint64_t *src64_1 = (uint64_t*)(src + stride / sizeof(uint16_t));
        
        ((av_alias64*)(src64_0 + 0))->u64 = dc;
        ((av_alias64*)(src64_0 + 1))->u64 = dc;
        ((av_alias64*)(src64_1 + 0))->u64 = dc ^ 0x1234567812345678ULL;
        ((av_alias64*)(src64_1 + 1))->u64 = dc ^ 0x8765432187654321ULL;

        src += 2 * stride;
    }
}
