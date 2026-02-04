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
    // Variant 2: Strided access with increased stride step (access every other row, deeper striding)
    ptrdiff_t extended_stride = stride * 2; // Double the effective stride
    for (i = 6; i < 8; i++) {
        uint16_t *offset_src = src + i * extended_stride;
        ((av_alias64 *)((uint64_t *)offset_src))->u64 = dc6splat;
        ((av_alias64 *)((uint64_t *)offset_src + 1))->u64 = dc7splat;
    }
}
