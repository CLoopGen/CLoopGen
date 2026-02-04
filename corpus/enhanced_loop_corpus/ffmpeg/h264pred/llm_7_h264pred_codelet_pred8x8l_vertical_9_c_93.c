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

extern int y;
extern uint16_t *src;
extern int stride;
extern uint64_t a;
extern uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies entirely; make each iteration independent
    // Use locally modified versions of 'a' and 'b' based only on loop index
    for (y = 1; y < 8; y++) {
        uint64_t local_a = a ^ (y * 0x11111111ULL);   // No dependency on prior iterations
        uint64_t local_b = b ^ ((7 - y) * 0x22222222ULL);
        (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 0))->u64 = (local_a));
        (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 1))->u64 = (local_b));
    }
}
