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

extern uint8_t *src;
extern int stride;
extern  uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies entirely; make each iteration independent
    // Use constant base value 'dc' directly in each iteration without modification
    for (y = 0; y < 8; y++) {
        uint8_t *local_src = src + y * stride; // Remove pointer update side effect; compute address directly
        // Unroll-like pattern with fixed offset access but retain loop structure
        (((av_alias32 *)(((uint32_t *)local_src) + 0))->u32 = dc);
        (((av_alias32 *)(((uint32_t *)local_src) + 1))->u32 = dc);
        // No modification to shared state (e.g., dc or src) inside loop → full independence
    }
}
