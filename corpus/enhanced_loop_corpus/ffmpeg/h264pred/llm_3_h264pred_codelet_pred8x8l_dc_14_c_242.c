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

extern uint16_t *src;
extern int stride;
extern  uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and byte-level offset calculation
    uint8_t *base = (uint8_t *)src;
    int step = stride * sizeof(uint16_t); // Convert stride to bytes
    for (y = 7; y >= 0; y--) {
        uint64_t *target = (uint64_t *)(base + y * step);
        ((av_alias64 *)(target + 0))->u64 = dc;
        ((av_alias64 *)(target + 1))->u64 = dc;
    }
}
