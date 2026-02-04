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
extern uint64_t dc6splat;
extern uint64_t dc7splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc6, local_dc7;
    for (i = 12; i < 16; i++) {
        // Eliminate loop-carried dependencies entirely by using local temporaries
        // Each iteration is now independent (increased parallelism potential)
        local_dc6 = dc6splat ^ (i * 0x1111111111111111ULL); // Remove RAW on previous i
        local_dc7 = dc7splat ^ (i * 0x2222222222222222ULL);
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = local_dc6;
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = local_dc7;
        // No state carried between iterations — fully parallelizable
    }
}
