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
extern uint16_t *dst;
extern uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *access_pattern[8] = {
        dst + 28, dst + 0, dst + 12, dst + 24,
        dst + 8, dst + 20, dst + 4, dst + 16
    };
    for (y = 0; y < 32; y++) {
        for (int j = 0; j < 8; j++) {
            ((av_alias64 *)access_pattern[j])->u64 = dc;
        }
        dst += stride;
        for (int j = 0; j < 8; j++) {
            access_pattern[j] += stride;
        }
    }
}
