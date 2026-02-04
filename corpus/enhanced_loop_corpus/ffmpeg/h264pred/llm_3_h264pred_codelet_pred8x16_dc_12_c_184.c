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
    // Variant 2: Strided access with reversed iteration order
    ptrdiff_t offset = 11 * stride;
    for (i = 11; i >= 8; i--) {
        uint16_t *ptr = src + offset;
        (((av_alias64 *)(((uint64_t *)ptr) + 0))->u64 = dc4splat);
        (((av_alias64 *)(((uint64_t *)ptr) + 1))->u64 = dc5splat);
        offset -= stride;
    }
}
