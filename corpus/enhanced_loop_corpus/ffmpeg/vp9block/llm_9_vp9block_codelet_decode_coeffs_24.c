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

extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < end_y && (n + 15) < end_y; n += 16) {
        const av_alias64 *a0 = (const av_alias64 *)(&l[n]);
        const av_alias64 *a1 = (const av_alias64 *)(&l[n + 8]);
        uint8_t combined = !!(a0->u64) + !!(a1->u64);
        l[n] = (combined > 0) ? 1 : 0;
        l[n + 4] = (combined == 2) ? 1 : 0;
        l[n + 8] = (combined > 0) ? 1 : 0;
        l[n + 12] = (combined == 1) ? 1 : 0;
    }
}
