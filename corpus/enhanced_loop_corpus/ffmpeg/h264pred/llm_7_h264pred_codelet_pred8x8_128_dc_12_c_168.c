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
extern  uint64_t a;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_a = a;
    for (i = 0; i < 8; i++) {
        uint64_t *base_ptr = (uint64_t *)(src + i * stride);
        av_alias64 val;
        val.u64 = local_a;
        // Remove potential write-after-write dependency by splitting assignment through temporary
        ((av_alias64 *)(base_ptr + 0))->u64 = val.u64;
        ((av_alias64 *)(base_ptr + 1))->u64 = val.u64;
        // Independent operations with no loop-carried dependencies
    }
}
