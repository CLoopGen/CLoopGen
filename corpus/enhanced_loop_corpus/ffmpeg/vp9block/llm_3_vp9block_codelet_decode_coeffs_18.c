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
    // Variant 2: Strided memory access with increasing stride
    // Access elements in a non-consecutive, strided manner to change memory access pattern
    // Here we use a fixed stride of 8, effectively skipping over locations
    const int stride = 8;
    for (n = 0; n < end_x; n += stride) {
        if (n + 7 < end_x) {  // Ensure buffer bounds
            av_alias64 *target = (av_alias64 *)&a[n];
            target->u64 = a[n] * 72340172838076673ULL;
        }
    }
    // Final pass to cover any missed indices with smaller step if needed
    for (int i = 0; i < stride - 4; i++) {
        for (n = i + 4; n < end_x; n += stride) {
            ((av_alias64 *)(&a[n]))->u64 = (a[n] * 72340172838076673ULL);
        }
    }
}
