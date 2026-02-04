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
        av_alias32 *a = (av_alias32 *)&l[n];
        a->u32 = (l[n] * 16843009);
        if (n + 4 < end_y) {
            av_alias32 *b = (av_alias32 *)&l[n + 4];
            b->u32 = (l[n + 4] * 16843009);
        }
    }
}
