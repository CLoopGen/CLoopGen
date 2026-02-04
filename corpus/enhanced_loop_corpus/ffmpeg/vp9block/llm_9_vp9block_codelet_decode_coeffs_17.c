#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < end_x; n += 2) {
        uint32_t val1 = a[n] * 256 + a[n];
        uint32_t val2 = val1 * 65537;
        ((av_alias32 *)(&a[n]))->u32 = val2;
        if (n + 1 < end_x) {
            ((av_alias32 *)(&a[n + 1]))->u8[0] = (uint8_t)(val2 >> 8);
        }
    }
}
