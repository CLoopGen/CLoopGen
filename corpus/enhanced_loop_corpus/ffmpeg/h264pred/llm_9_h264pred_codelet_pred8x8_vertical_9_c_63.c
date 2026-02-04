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
    uint64_t local_a = a;
    uint64_t local_b = b;
    for (i = 0; i < 4; i++) {
        uint16_t *row = src + i * stride;
        ((av_alias64 *)((uint64_t *)row + 0))->u64 = local_a;
        ((av_alias64 *)((uint64_t *)row + 1))->u64 = local_b;
        
        // Unrolled: repeat with modified values to increase compute intensity
        ((av_alias64 *)((uint64_t *)row + 2))->u64 = local_a ^ local_b;
        ((av_alias64 *)((uint64_t *)row + 3))->u64 = local_b ^ 0xFFFFFFFFFFFFFFFFULL;
    }
}
