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
for (i = 0; i < 4; i++) {
    int index = 12 + i;
    uint64_t *base = (uint64_t *)(src + index * stride);
    ((av_alias64 *)base)->u64 = (i & 1) ? dc7splat : dc6splat;
    ((av_alias64 *)(base + 1))->u64 = (i & 1) ? dc6splat : dc7splat;
}
}
