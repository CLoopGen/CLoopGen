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
    for (n = 0; n < end_x; n += 16) {
        const av_alias64 *p = (const av_alias64 *)(&a[n]);
        const av_alias64 *q = (const av_alias64 *)(&a[n + 8]);
        uint64_t combined = p->u64 | (n + 8 < end_x ? q->u64 : 0);
        a[n] = !!(combined);
        a[n + 4] = !!(combined >> 32);
        a[n + 8] = !!(combined >> 64);
    }
}
