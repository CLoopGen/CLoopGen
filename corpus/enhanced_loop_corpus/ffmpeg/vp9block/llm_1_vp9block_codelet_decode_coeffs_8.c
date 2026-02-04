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
        if (n + 0 < end_x) {
            (((av_alias64 *)(&a[n + 0]))->u64 = (a[n + 0] * 72340172838076673ULL));
        }
        if (n + 2 < end_x) {
            (((av_alias64 *)(&a[n + 2]))->u64 = (a[n + 2] * 72340172838076673ULL));
        }
    }
}
