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
    for (n = 0; n < end_x; n += 4) {
        uint64_t val = ((const av_alias64 *)(&a[n]))->u64;
        a[n] = !!(val & 0xFF);
        if (n + 1 < end_x) a[n + 1] = !!(val & 0xFF00);
        if (n + 2 < end_x) a[n + 2] = !!(val & 0xFF0000);
        if (n + 3 < end_x) a[n + 3] = !!(val & 0xFF000000);
    }
}
