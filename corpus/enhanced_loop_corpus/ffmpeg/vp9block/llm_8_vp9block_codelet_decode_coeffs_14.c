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

extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < end_y; n += 8) {
        uint32_t val1 = ((const av_alias32 *)(&l[n]))->u32;
        uint32_t val2 = (n + 4 < end_y) ? ((const av_alias32 *)(&l[n + 4]))->u32 : 0;
        l[n] = !!(val1);
        if (n + 4 < end_y)
            l[n + 4] = !!(val2);
    }
}
