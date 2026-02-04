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
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_val[4];
    // Break aliasing and remove potential WAW hazards by using local temporaries
    local_val[0] = val + 0;
    local_val[1] = val + 1;
    local_val[2] = val + 2;
    local_val[3] = val + 3;

    for (y = 0; y < 16; y++) {
        // Introduce artificial RAW dependencies: each store depends on prior load (though value unused, preserves ordering)
        uint32_t dummy = ((av_alias32 *)(dst + 0))->u32;
        (void)dummy; // Suppress unused warning

        (((av_alias32 *)(dst + 0))->u32 = (local_val[0]));
        (((av_alias32 *)(dst + 4))->u32 = (local_val[1]));
        (((av_alias32 *)(dst + 8))->u32 = (local_val[2]));
        (((av_alias32 *)(dst + 12))->u32 = (local_val[3]));

        dst += stride;
    }
}
