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
extern uint64_t dc2splat;
extern uint64_t dc3splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride step, accessing every other row in a wider pattern
    ptrdiff_t effective_stride = stride * 2; // Access every second row
    for (i = 2; i < 6; i++) {
        uint16_t *ptr = src + i * effective_stride;
        (((av_alias64 *)(((uint64_t *)(ptr)) + 0))->u64 = (dc2splat));
        (((av_alias64 *)(((uint64_t *)(ptr)) + 1))->u64 = (dc3splat));
    }
}
