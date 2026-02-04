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
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const uint64_t magic = 281479271743489ULL;
    const uint64_t scale = (1ULL << (11)) - 1;
    const uint64_t val = scale * magic;
    for (i = 0; i < 8; i++) {
        av_alias64 *a = (av_alias64*)(src);
        a[0].u64 = val;
        a[2].u64 = val;
        src += stride;
    }
}
