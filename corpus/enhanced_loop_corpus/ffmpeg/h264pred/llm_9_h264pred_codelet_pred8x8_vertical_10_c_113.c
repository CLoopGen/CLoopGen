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
    uint64_t local_a = a, local_b = b;
    for (i = 0; i < 4; i++) {  // Reduce trip count by half
        // Perform multiple operations per iteration to increase computational density
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = local_a;
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = local_b;

        // Additional arithmetic to increase intensity
        local_a = (local_a << 1) | (local_a >> 63);  // Rotate left by 1
        local_b = (local_b >> 1) | (local_b << 63);  // Rotate right by 1

        // Second write using transformed values
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 2))->u64 = local_a ^ 0xFFFFFFFFFFFFFFFF;
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 3))->u64 = local_b ^ 0xAAAAAAAAAAAAAAAA;
    }
}
