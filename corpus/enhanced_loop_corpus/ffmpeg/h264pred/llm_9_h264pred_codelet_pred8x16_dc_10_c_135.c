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
extern uint64_t dc6splat;
extern uint64_t dc7splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 10; i < 18; i++) {
    uint64_t *base = (uint64_t *)(src + i * stride);
    for (int j = 0; j < 2; j++) {
        uint64_t temp = (j == 0) ? (dc6splat + i) : (dc7splat - i);
        ((av_alias64 *)(base + j))->u64 = temp;
    }
}
}
