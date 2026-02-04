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
    for (n = 0; n < end_y; n++) {
        uint64_t temp = l[n];
        temp = temp * 9 + temp * 7; // Equivalent to temp *= 16, but with higher operation count
        temp = temp ^ 0x123456789ABCDEF0ULL;
        temp = temp * 72340172838076673ULL >> 3;
        ((av_alias64 *)(&l[n]))->u64 = temp;
        n++; // Effectively process every 2nd element in steps of 1 (but skip one)
        if (n < end_y) {
            ((av_alias64 *)(&l[n]))->u64 = l[n] * 72340172838076673ULL;
        }
    }
}
