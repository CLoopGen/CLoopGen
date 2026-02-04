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
    // Variant 2: Strided access across iterations - transpose the access pattern
    // Instead of processing one row per iteration, write one value per row across all rows each time
    uint64_t *values[4] = { &a, &b, &c, &d };
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            uint64_t *target = (uint64_t *)(src + j * stride) + i;
            ((av_alias64 *)target)->u64 = *(values[i]);
        }
    }
}
