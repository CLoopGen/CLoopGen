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
extern uint32_t dc4splat;
extern uint32_t dc5splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_dc4 = dc4splat;
    uint32_t local_dc5 = dc5splat;
    for (i = 8; i < 12; i++) {
        // Reorder memory stores to break potential WAW or WAR hazards
        // Store dc5 before dc4 — changed store order introduces different data dependence pattern
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = (local_dc5));
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = (local_dc4));
    }
    // Eliminate any loop-carried dependency by making all accesses independent and using local const copies
    // No modification of dc4/dc5 across iterations — pure loop-independent operations
}
