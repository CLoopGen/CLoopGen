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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t base_val = (((1 << (8 - 1)) - 1) * 16843009U);
    uint32_t offset_val = 0;
    for (i = 0; i < 16; i++) {
        // Introduce WAW and WAR by reusing and modifying offset_val in a loop-carried manner
        offset_val = base_val ^ (offset_val >> i); // Loop-carried dependency via offset_val
        
        ((av_alias32 *)(src + 0))->u32 = base_val;
        ((av_alias32 *)(src + 4))->u32 = offset_val;
        ((av_alias32 *)(src + 8))->u32 = base_val;
        ((av_alias32 *)(src + 12))->u32 = offset_val;

        // Modify src after stores to break direct data dependency on memory (WAR-like scheduling)
        if (i % 2 == 0) {
            src += stride;
        } else {
            src += stride + 4;
        }
    }
}
