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
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t base_val = ((1ULL << (14 - 1)) * 281479271743489ULL);
    uint64_t dependent_val = base_val ^ 0x1234567887654321ULL;
    for (y = 0; y < 8; y++) {
        if (y > 0) {
            (((av_alias64 *)(((uint64_t *)src) + 0))->u64 = dependent_val);
            (((av_alias64 *)(((uint64_t *)src) + 1))->u64 = dependent_val);
            dependent_val ^= base_val;
        } else {
            (((av_alias64 *)(((uint64_t *)src) + 0))->u64 = base_val);
            (((av_alias64 *)(((uint64_t *)src) + 1))->u64 = base_val);
        }
        src += stride;
    }
}
