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

extern int i;
extern uint16_t *src;
extern int stride;
extern  uint64_t a;
extern  uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and alternating assignment order
    uint64_t *ptr;
    for (i = 15; i >= 0; i--) {
        ptr = (uint64_t *)(src + i * stride);
        // Swap assignment order: write 'b' first, then 'a'
        ((av_alias64 *)(ptr + 1))->u64 = b;
        ((av_alias64 *)(ptr + 0))->u64 = a;
    }
}
