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
extern uint16_t *dst;
extern uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc[8];
    for (y = 0; y < 32; y++) {
        // Break aliasing assumptions with local array, remove direct dependencies across stores
        local_dc[0] = dc + 0;
        local_dc[1] = dc + 1;
        local_dc[2] = dc + 2;
        local_dc[3] = dc + 3;
        local_dc[4] = dc + 4;
        local_dc[5] = dc + 5;
        local_dc[6] = dc + 6;
        local_dc[7] = dc + 7;

        ((av_alias64*)(dst + 0 ))->u64 = local_dc[0];
        ((av_alias64*)(dst + 4 ))->u64 = local_dc[1];
        ((av_alias64*)(dst + 8 ))->u64 = local_dc[2];
        ((av_alias64*)(dst + 12))->u64 = local_dc[3];
        ((av_alias64*)(dst + 16))->u64 = local_dc[4];
        ((av_alias64*)(dst + 20))->u64 = local_dc[5];
        ((av_alias64*)(dst + 24))->u64 = local_dc[6];
        ((av_alias64*)(dst + 28))->u64 = local_dc[7];

        // Eliminate loop-carried dependency by making each write independent
        // All values derived only from loop-invariant 'dc', no state carried between iterations
        dst += stride;
    }
}
