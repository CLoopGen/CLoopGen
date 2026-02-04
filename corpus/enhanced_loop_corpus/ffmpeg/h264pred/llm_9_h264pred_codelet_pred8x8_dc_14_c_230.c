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
extern uint64_t dc2splat;
extern uint64_t dc3splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < 8; i++) {
    uint16_t *ptr1 = src + i * stride;
    uint16_t *ptr2 = src + (i + 4) * stride;
    ((av_alias64 *)((uint64_t *)ptr1 + 0))->u64 = dc2splat;
    ((av_alias64 *)((uint64_t *)ptr1 + 1))->u64 = dc3splat;
    ((av_alias64 *)((uint64_t *)ptr2 + 0))->u64 = dc2splat;
    ((av_alias64 *)((uint64_t *)ptr2 + 1))->u64 = dc3splat;
    ((av_alias64 *)((uint64_t *)ptr1 + 2))->u64 = dc2splat ^ dc3splat;
    ((av_alias64 *)((uint64_t *)ptr1 + 3))->u64 = dc3splat ^ dc2splat;
}
}
