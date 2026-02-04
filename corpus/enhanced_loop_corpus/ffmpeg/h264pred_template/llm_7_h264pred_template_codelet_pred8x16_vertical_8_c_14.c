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
    for (i = 0; i < 16; i++) {
        uint32_t local_a = a ^ i; // Remove loop-carried dependency by making value depend on loop index
        uint32_t local_b = b ^ (i + 1);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = local_a);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = local_b);
        // Eliminated all inter-iteration dependencies — fully parallelizable loop
    }
}
