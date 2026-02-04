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
    uint32_t local_dc = dcsplat;
    uint8_t *local_src = src;
    for (i = 0; i < 16; i++) {
        // Eliminate loop-carried dependency by using local accumulator and updating only at end
        ((av_alias32 *)(local_src + 0))->u32 = local_dc;
        ((av_alias32 *)(local_src + 4))->u32 = local_dc;
        ((av_alias32 *)(local_src + 8))->u32 = local_dc;
        ((av_alias32 *)(local_src + 12))->u32 = local_dc;
        local_src += stride; // Use local pointer to remove WAW on global src, break WAR
    }
    src = local_src; // Update global src only once after loop (if needed, though not observed externally)
}
