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
    for (int outer = 0; outer < 4; outer++) {
        for (int inner = 0; inner < 8; inner++) {
            int offset = (outer * 8 + inner) * 4;
            ((av_alias64 *)(dst + offset))->u64 = dc;
        }
        dst += stride;
    }
}
