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
extern  uint64_t c;
extern  uint64_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        uint16_t* base = src + i * stride * 2;
        uint64_t temp_a = a + i;
        uint64_t temp_b = b - i;
        uint64_t temp_c = c + (i << 1);
        uint64_t temp_d = d - (i * 3);

        ((av_alias64*)(((uint64_t*)base) + 0))->u64 = temp_a;
        ((av_alias64*)(((uint64_t*)base) + 1))->u64 = temp_b;
        ((av_alias64*)(((uint64_t*)base) + 2))->u64 = temp_c;
        ((av_alias64*)(((uint64_t*)base) + 3))->u64 = temp_d;

        base += stride;
        ((av_alias64*)(((uint64_t*)base) + 0))->u64 = temp_d;
        ((av_alias64*)(((uint64_t*)base) + 1))->u64 = temp_c;
        ((av_alias64*)(((uint64_t*)base) + 2))->u64 = temp_b;
        ((av_alias64*)(((uint64_t*)base) + 3))->u64 = temp_a;
    }
}
