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
    for (n = 0; n < end_x; n += 8) {
        volatile uint64_t val = ((const av_alias64 *)(&a[n]))->u64;
        a[n] = !!(val);
        a[n + 1] = !!(val >> 8);
        a[n + 2] = !!(val >> 16);
        a[n + 3] = !!(val >> 24);
        a[n + 4] = !!(val >> 32);
        a[n + 5] = !!(val >> 40);
        a[n + 6] = !!(val >> 48);
        a[n + 7] = !!(val >> 56);
    }
}
