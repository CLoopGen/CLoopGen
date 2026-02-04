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
for (i = 12; i < 16; i++) {
    uint64_t *base_ptr = (uint64_t *)(src + i * stride);
    av_alias64 *alias_ptr1 = (av_alias64 *)(base_ptr + 0);
    av_alias64 *alias_ptr2 = (av_alias64 *)(base_ptr + 1);
    alias_ptr1->u64 = dc6splat ^ 0x8000800080008000ULL;
    alias_ptr2->u64 = dc7splat ^ 0x8000800080008000ULL;
    alias_ptr1->u64 += 1;
    alias_ptr2->u64 += 1;
}
}
