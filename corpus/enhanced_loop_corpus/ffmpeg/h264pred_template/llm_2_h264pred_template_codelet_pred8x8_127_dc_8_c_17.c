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
extern int i;
extern  uint32_t a;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (coalesced)
    uint32_t *base = (uint32_t *)src;
    for (i = 0; i < 8; i++) {
        av_alias32 *addr1 = (av_alias32 *)&base[i * 2];
        av_alias32 *addr2 = (av_alias32 *)&base[i * 2 + 1];
        addr1->u32 = a;
        addr2->u32 = a;
    }
}
