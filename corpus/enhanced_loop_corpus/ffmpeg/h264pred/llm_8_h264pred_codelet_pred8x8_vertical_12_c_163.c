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
    for (i = 0; i < 16; i += 2) {
        uint16_t *row1 = src + i * stride;
        uint16_t *row2 = src + (i + 1) * stride;
        av_alias64 *a1 = (av_alias64*)row1;
        av_alias64 *a2 = (av_alias64*)(row1 + 4);
        av_alias64 *b1 = (av_alias64*)row2;
        av_alias64 *b2 = (av_alias64*)(row2 + 4);
        a1->u64 = a;
        a2->u64 = b;
        b1->u64 = a;
        b2->u64 = b;
    }
}
