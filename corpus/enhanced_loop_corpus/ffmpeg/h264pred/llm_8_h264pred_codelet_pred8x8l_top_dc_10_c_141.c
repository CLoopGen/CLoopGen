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
    uint64_t dc_local = dc;
    for (y = 0; y < 16; y++) {
        ((av_alias64*)(((uint64_t*)src) + 0))->u64 = dc_local ^ 0x5555555555555555ULL;
        ((av_alias64*)(((uint64_t*)src) + 1))->u64 = dc_local ^ 0xAAAAAAAAAAAAAAAAULL;
        dc_local += y * 3;
        src += stride;
    }
}
