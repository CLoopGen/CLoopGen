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
    uint16_t *temp_src[16];
    ptrdiff_t s = stride;
    for (i = 0; i < 16; i++) {
        temp_src[i] = src + i * s;
    }
    uint64_t computed_val = (((1 << (14 - 1)) - 1) * 281479271743489ULL);
    for (i = 0; i < 16; i++) {
        av_alias64 *a = (av_alias64*)(temp_src[i] + 0);
        av_alias64 *b = (av_alias64*)(temp_src[i] + 4);
        av_alias64 *c = (av_alias64*)(temp_src[i] + 8);
        av_alias64 *d = (av_alias64*)(temp_src[i] + 12);
        d->u64 = computed_val;
        c->u64 = computed_val;
        b->u64 = computed_val;
        a->u64 = computed_val;
    }
}
