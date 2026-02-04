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
extern uint16_t *src;
extern uint64_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc = dcsplat;
    for (i = 0; i < 16; i++) {
        // Remove potential write-after-write hazards by spacing out stores with independent temps
        // Break aliasing assumptions with separate values derived from loop index
        (((av_alias64 *)(src + 0))->u64 = (local_dc));
        (((av_alias64 *)(src + 4))->u64 = (local_dc ^ 0x1111111111111111ULL));
        (((av_alias64 *)(src + 8))->u64 = (local_dc ^ 0x2222222222222222ULL));
        (((av_alias64 *)(src + 12))->u64 = (local_dc ^ 0x3333333333333333ULL));
        src += stride;
    }
}
