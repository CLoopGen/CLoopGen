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
for (i = 4; i < 12; i += 2) {
    uint64_t *base1 = (uint64_t *)(src + i * stride);
    uint64_t *base2 = (uint64_t *)(src + (i + 1) * stride);
    av_alias64 val1, val2;
    val1.u64 = dc2splat ^ 0x123456789ABCDEF0ULL; // Additional arithmetic: XOR
    val2.u64 = dc3splat ^ 0xFEDCBA9876543210ULL;
    ((av_alias64*)base1)->u64 = val1.u64;
    ((av_alias64*)(base1 + 1))->u64 = val2.u64;
    ((av_alias64*)base2)->u64 = val2.u64;
    ((av_alias64*)(base2 + 1))->u64 = val1.u64;
}
}
