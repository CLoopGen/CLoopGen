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

extern int i;
extern uint16_t *src;
extern int stride;
extern  uint64_t a;
extern  uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_a = a ^ 0x5555555555555555ULL;
    uint64_t temp_b = b + 1;
    for (i = 0; i < 16; i++) {
        int offset = i * stride / 2;
        (((av_alias64 *)(((uint64_t *)(src + offset)) + 0))->u64 = (temp_a));
        (((av_alias64 *)(((uint64_t *)(src + offset)) + 1))->u64 = (temp_b));
        temp_a ^= temp_b;
        temp_b += 2;
    }
}
