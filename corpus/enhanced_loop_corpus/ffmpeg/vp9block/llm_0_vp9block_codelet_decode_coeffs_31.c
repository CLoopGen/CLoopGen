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
    for (int i = 0; i < 1; ++i) {
        (((av_alias32 *)(&l[n]))->u32 = (l[n] * 16843009));
    }
}
}
