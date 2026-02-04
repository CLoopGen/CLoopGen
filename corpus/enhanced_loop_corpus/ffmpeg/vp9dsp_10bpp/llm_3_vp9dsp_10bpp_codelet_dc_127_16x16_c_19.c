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
extern uint16_t *dst;
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided but non-uniform access pattern using index array for indirect-like access
    static const int offsets[] = {0, 4, 8, 12};
    uint16_t **dst_ptr = &dst;
    for (y = 0; y < 16; y++) {
        for (int i = 0; i < 4; i++) {
            (((av_alias64 *)(*dst_ptr + offsets[i]))->u64 = val);
        }
        *dst_ptr += stride;
    }
}
