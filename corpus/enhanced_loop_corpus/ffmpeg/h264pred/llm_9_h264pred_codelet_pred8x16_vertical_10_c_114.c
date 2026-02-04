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
    for (i = 0; i < 8; i++) {
        uint64_t modified_a = a + (i * 0x100);
        uint64_t modified_b = b - (i * 0x50);
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = modified_a;
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = modified_b;
        
        // Duplicate store with offset to increase memory operations slightly
        if (i < 4) {
            ((av_alias64 *)(((uint64_t *)(src + (i + 8) * stride)) + 0))->u64 = modified_a ^ b;
            ((av_alias64 *)(((uint64_t *)(src + (i + 8) * stride)) + 1))->u64 = modified_b ^ a;
        }
    }
}
