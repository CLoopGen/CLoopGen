#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern int i;
extern uint8_t *src;
extern int stride;
extern  uint32_t a;
extern  uint32_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_a[8], local_b[8];
    // Precompute all values outside the main store loop to remove loop-carried dependencies
    for (int j = 0; j < 8; j++) {
        local_a[j] = a ^ (j << 2); // Remove dependency on previous iterations; independent computation
        local_b[j] = b ^ (j << 2);
    }
    for (i = 0; i < 8; i++) {
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = (local_a[i]));
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = (local_b[i]));
    }
}
