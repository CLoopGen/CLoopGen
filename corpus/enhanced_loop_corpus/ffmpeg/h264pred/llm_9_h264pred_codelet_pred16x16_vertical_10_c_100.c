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
    uint16_t* base1 = src + i * stride;
    uint16_t* base2 = src + (i + 8) * stride;
    
    uint64_t temp_a = a + 1;
    uint64_t temp_b = b + 2;
    uint64_t temp_c = c + 3;
    uint64_t temp_d = d + 4;

    (((av_alias64 *)(((uint64_t *)(base1)) + 0))->u64 = (temp_a));
    (((av_alias64 *)(((uint64_t *)(base1)) + 1))->u64 = (temp_b));
    (((av_alias64 *)(((uint64_t *)(base1)) + 2))->u64 = (temp_c));
    (((av_alias64 *)(((uint64_t *)(base1)) + 3))->u64 = (temp_d));

    (((av_alias64 *)(((uint64_t *)(base2)) + 0))->u64 = (temp_d));
    (((av_alias64 *)(((uint64_t *)(base2)) + 1))->u64 = (temp_c));
    (((av_alias64 *)(((uint64_t *)(base2)) + 2))->u64 = (temp_b));
    (((av_alias64 *)(((uint64_t *)(base2)) + 3))->u64 = (temp_a));
}
}
