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
    uint64_t temp[8]; // Introduce temporary storage to modify data dependencies
    for (i = 0; i < 8; i++) {
        const uint64_t a = ((src[-1 + i * stride]) * 281479271743489ULL);
        temp[i] = a; // Store computed values to break immediate write-after-write (WAW) and enable reuse
    }
    // Second pass: use stored values — introduces loop-carried dependence on temp, removes RAW from memory
    for (i = 0; i < 8; i++) {
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (temp[i]));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (temp[i]));
    }
}
