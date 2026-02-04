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
extern uint8_t *src;
extern uint32_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_src = src;
    uint32_t prev_value = 0;
    for (i = 0; i < 16; i++) {
        // Introduce RAW dependency: each write depends on prior read
        prev_value = ((av_alias32 *)(local_src + 0))->u32;
        ((av_alias32 *)(local_src + 0))->u32 = dcsplat ^ prev_value;
        ((av_alias32 *)(local_src + 4))->u32 = dcsplat ^ ((av_alias32 *)(local_src + 0))->u32;
        ((av_alias32 *)(local_src + 8))->u32 = dcsplat ^ ((av_alias32 *)(local_src + 4))->u32;
        ((av_alias32 *)(local_src + 12))->u32 = dcsplat ^ ((av_alias32 *)(local_src + 8))->u32;

        local_src += stride;
    }
    src = local_src; // Update original pointer only at end (eliminate loop-carried WAR)
}
