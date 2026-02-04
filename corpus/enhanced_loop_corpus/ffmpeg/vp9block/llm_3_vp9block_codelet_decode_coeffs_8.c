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

extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 4th element in a staggered pattern
    const int stride = 4;
    for (n = 0; n < end_x; n += stride) {
        if (n + 1 < end_x) {
            av_alias64 *ptr = (av_alias64*)(&a[n]);
            ptr->u64 = ((uint64_t)a[n] * 72340172838076673ULL);
        }
    }
    // Secondary pass for offset start to simulate full coverage with stride
    for (n = 2; n < end_x; n += stride) {
        if (n + 1 < end_x) {
            av_alias64 *ptr = (av_alias64*)(&a[n]);
            ptr->u64 = ((uint64_t)a[n] * 72340172838076673ULL);
        }
    }
}
