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
    uint16_t *index_map[8];
    for (int i = 0; i < 8; i++) {
        index_map[i] = src + i * stride;
    }
    for (y = 0; y < 8; y++) {
        uint16_t *indirect_ptr = index_map[y];
        ((av_alias64*)((uint64_t*)indirect_ptr + 0))->u64 = dc;
        ((av_alias64*)((uint64_t*)indirect_ptr + 1))->u64 = dc;
    }
}
