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
extern  uint64_t c;
extern  uint64_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed iteration - process same offset across all rows first
    for (int offset = 0; offset < 4; offset++) {
        uint64_t val;
        switch (offset) {
            case 0: val = a; break;
            case 1: val = b; break;
            case 2: val = c; break;
            case 3: val = d; break;
            default: val = 0;
        }
        for (i = 0; i < 16; i++) {
            ((av_alias64*)(((uint64_t*)(src + i * stride)) + offset))->u64 = val;
        }
    }
}
