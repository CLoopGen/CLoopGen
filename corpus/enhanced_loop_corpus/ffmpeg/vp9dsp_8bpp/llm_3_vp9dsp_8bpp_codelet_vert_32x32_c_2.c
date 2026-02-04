#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern uint8_t *dst;
extern uint32_t p4a;
extern uint32_t p4b;
extern uint32_t p4c;
extern uint32_t p4d;
extern uint32_t p4e;
extern uint32_t p4f;
extern uint32_t p4g;
extern uint32_t p4h;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access using array of pointers to simulate scattered destination layout
    uint8_t **access_ptrs = (uint8_t**)alloca(32 * sizeof(uint8_t*));
    for (y = 0; y < 32; y++) {
        access_ptrs[y] = dst + y * stride;
    }
    for (y = 0; y < 32; y++) {
        uint8_t *base = access_ptrs[y];
        ((av_alias32 *)(base + 0))->u32 = p4a;
        ((av_alias32 *)(base + 4))->u32 = p4b;
        ((av_alias32 *)(base + 8))->u32 = p4c;
        ((av_alias32 *)(base + 12))->u32 = p4d;
        ((av_alias32 *)(base + 16))->u32 = p4e;
        ((av_alias32 *)(base + 20))->u32 = p4f;
        ((av_alias32 *)(base + 24))->u32 = p4g;
        ((av_alias32 *)(base + 28))->u32 = p4h;
    }
}
