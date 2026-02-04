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
    for (y = 0; y < 4; y++) {
        uint64_t temp1 = dc + 0x123456789ABCDEF0ULL;
        uint64_t temp2 = dc - 0xABCDEF0987654321ULL;
        (((av_alias64 *)(((uint64_t *)src) + 0))->u64 = temp1);
        (((av_alias64 *)(((uint64_t *)src) + 1))->u64 = temp2);
        src += stride;
        (((av_alias64 *)(((uint64_t *)src) + 0))->u64 = temp2);
        (((av_alias64 *)(((uint64_t *)src) + 1))->u64 = temp1);
        src += stride;
    }
}
