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



void loop() {
    uint16_t *access_pattern[8];
    for (y = 0; y < 8; y++) {
        access_pattern[y] = src + y * stride;
    }
    for (y = 0; y < 8; y++) {
        uint64_t *row = (uint64_t*)access_pattern[y];
        ((av_alias64*)(row + 0))->u64 = dc;
        ((av_alias64*)(row + 1))->u64 = dc;
    }
}
