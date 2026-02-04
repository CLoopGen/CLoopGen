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
extern uint64_t dc4splat;
extern uint64_t dc5splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc4, local_dc5;
    for (i = 8; i < 12; i++) {
        // Remove loop-carried dependencies by using independent local copies
        local_dc4 = dc4splat ^ (i << 8);  // Break potential WAW on dc4splat with immediate
        local_dc5 = dc5splat ^ (i << 16); // Break potential WAW on dc5splat
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = local_dc4);
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = local_dc5);
        // No data carried between iterations — fully parallelizable
    }
}
