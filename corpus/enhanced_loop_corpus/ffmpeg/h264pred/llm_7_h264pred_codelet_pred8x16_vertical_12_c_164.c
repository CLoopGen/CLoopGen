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
    uint64_t local_a[16];
    uint64_t local_b[16];
    // Precompute values outside the main store loop to remove write-after-write dependencies
    for (int j = 0; j < 16; j++) {
        local_a[j] = a ^ (j * j); // Introduce independent computation with no loop-carried dependency
        local_b[j] = b ^ (j * j);
    }
    for (i = 0; i < 16; i++) {
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (local_a[i]));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (local_b[i]));
    }
}
