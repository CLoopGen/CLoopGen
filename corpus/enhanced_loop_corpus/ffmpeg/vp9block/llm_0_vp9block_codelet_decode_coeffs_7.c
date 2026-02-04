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
    for (int outer = 0; outer < end_x; outer += 4) {
        for (n = outer; n < outer + 2 && n < end_x; n += 2)
            (((av_alias32 *)(&a[n]))->u32 = (a[n] * 16843009));
    }
}
