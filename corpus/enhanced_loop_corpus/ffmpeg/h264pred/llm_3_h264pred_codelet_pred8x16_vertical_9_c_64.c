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
    // Variant 2: Strided access with increased stride factor, stepping through every 2nd element first, then next set
    uint64_t *ptr = (uint64_t *)src;
    int large_stride = stride * 8; // Assuming original stride in uint16_t units, now scale to 8 elements ahead
    for (i = 0; i < 16; i++) {
        int index = (i * large_stride) / sizeof(uint64_t); // Convert byte offset logic into pointer arithmetic
        (((av_alias64 *)(ptr + index))->u64 = (a));
        (((av_alias64 *)(ptr + index + 1))->u64 = (b));
    }
}
