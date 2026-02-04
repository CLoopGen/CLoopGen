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
    for (n = 0; n < end_x; n += 8) {
        uint32_t val1 = ((const av_alias32 *)(&a[n + 0]))->u32;
        uint32_t val2 = (n + 4 < end_x) ? ((const av_alias32 *)(&a[n + 4]))->u32 : 0;
        a[n]     = !!(val1);
        if (n + 4 < end_x) a[n + 4] = !!(val2);
    }
}
