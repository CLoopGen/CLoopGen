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
extern uint16_t *dst;
extern uint64_t p4a;
extern uint64_t p4b;
extern uint64_t p4c;
extern uint64_t p4d;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_a = p4a;
    uint64_t temp_b = p4b;
    uint64_t temp_c = p4c;
    uint64_t temp_d = p4d;
    for (y = 0; y < 16; y++) {
        // Introduce temporary variables to break direct dependencies on globals
        // Create artificial RAW dependencies: each write depends on prior iteration's value
        temp_a ^= ((av_alias64 *)(dst + 0))->u64; // Read before write creates RAW
        temp_b ^= ((av_alias64 *)(dst + 4))->u64;
        temp_c ^= ((av_alias64 *)(dst + 8))->u64;
        temp_d ^= ((av_alias64 *)(dst + 12))->u64;

        (((av_alias64 *)(dst + 0))->u64 = temp_a);
        (((av_alias64 *)(dst + 4))->u64 = temp_b);
        (((av_alias64 *)(dst + 8))->u64 = temp_c);
        (((av_alias64 *)(dst + 12))->u64 = temp_d);

        // Update temps for next iteration to create loop-carried dependency
        temp_a += 0x1111;
        temp_b += 0x2222;
        temp_c += 0x3333;
        temp_d += 0x4444;

        dst += stride;
    }
}
