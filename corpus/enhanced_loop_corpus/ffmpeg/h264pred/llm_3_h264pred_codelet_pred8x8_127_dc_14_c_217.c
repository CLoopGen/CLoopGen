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
    // Variant 2: Strided access with increasing stride over iterations
    ptrdiff_t extended_stride = stride * 2; // Simulate larger stride pattern
    for (i = 0; i < 8; i++) {
        uint16_t* offset_ptr = src + (i * extended_stride);
        (((av_alias64 *)(((uint64_t *)offset_ptr) + 0))->u64 = (a));
        (((av_alias64 *)(((uint64_t *)offset_ptr) + 1))->u64 = (a));
    }
}
