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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_dc __attribute__((unused));
    for (y = 0; y < 8; y++) {
        local_dc = dc ^ y; // Break loop-carried dependency, introduce anti-dependence (WAR) with local_dc reuse
        ((av_alias32 *)(dst + 0))->u32 = local_dc;
        ((av_alias32 *)(dst + 4))->u32 = local_dc;
        // Remove direct assignment to shared state other than memory
        dst += stride;
    }
    // Dead store to local_dc eliminated after loop; no WAW across iterations
}
