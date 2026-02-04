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
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index array to simulate non-sequential pattern
    int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Interleaved row access
    uint64_t val = ((1 << (12 - 1)) * 281479271743489ULL);
    for (y = 0; y < 8; y++) {
        int idx = indices[y]; // Use indirection for access pattern
        uint64_t* row = (uint64_t*)(src + idx * (stride / sizeof(uint16_t)));
        ((av_alias64*)(row + 0))->u64 = val;
        ((av_alias64*)(row + 1))->u64 = val;
    }
}
