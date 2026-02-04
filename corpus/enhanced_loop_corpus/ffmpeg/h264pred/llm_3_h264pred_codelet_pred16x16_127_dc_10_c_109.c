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
extern int i;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increasing stride steps and sequential writes
    ptrdiff_t effective_stride = stride / sizeof(uint16_t);
    for (i = 0; i < 16; i++) {
        uint16_t *offset_src = src + i * effective_stride;
        // Write using a loop over the 4 alias64 slots instead of unrolling
        for (int j = 0; j < 4; j++) {
            ((av_alias64 *)(offset_src + j * 4))->u64 = (((1 << (10 - 1)) - 1) * 281479271743489ULL);
        }
    }
}
