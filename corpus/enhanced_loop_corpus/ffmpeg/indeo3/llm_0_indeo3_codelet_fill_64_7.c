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

extern uint8_t *dst;
extern  uint64_t pix;
extern int32_t n;
extern int32_t row_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < n; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            (((av_alias64 *)(dst))->u64 = (pix));
            dst += row_offset;
        }
    }
}
