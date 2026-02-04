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
for (n = 0; 2*n + 1 < end_y; n++) {
    int idx = 2 * n;
    uint32_t v32 = l[idx] * 16843009;
    (((av_alias32 *)(&l[idx]))->u32 = (v32));
    (((av_alias32 *)(&l[idx + 4]))->u32 = (v32));
}
}
