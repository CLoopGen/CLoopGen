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
    uint64_t prev_val = 0;
    for (n = 0; n < end_x; n += 2) {
        uint64_t computed = a[n] * 72340172838076673ULL + prev_val;
        (((av_alias64 *)(&a[n]))->u64 = computed);
        prev_val = computed;
    }
}
