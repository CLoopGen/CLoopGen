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
    uint16_t *temp_src = src;
    for (y = 0; y < 8; y++) {
        av_alias64 *a = (av_alias64*)temp_src;
        a[0].u64 = dc;
        a[1].u64 = dc;
        temp_src += stride;
    }
}
