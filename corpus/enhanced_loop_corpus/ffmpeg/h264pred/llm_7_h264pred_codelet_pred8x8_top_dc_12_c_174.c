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
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc0 = dc0splat;
    uint64_t local_dc1 = dc1splat;
    uint16_t *base_src = src;
    ptrdiff_t s = stride;
    for (i = 0; i < 4; i++) {
        uint64_t *row = (uint64_t *)(base_src + i * s);
        // Reverse store order to introduce WAR-like hazard (though not truly hazardous due to distinct offsets)
        ((av_alias64 *)(row + 1))->u64 = local_dc1;
        ((av_alias64 *)(row + 0))->u64 = local_dc0;
        // Eliminate any artificial loop-carried dependency; all work is independent
    }
    // No data carried between iterations — fully parallelizable with no loop-carried dependencies
}
