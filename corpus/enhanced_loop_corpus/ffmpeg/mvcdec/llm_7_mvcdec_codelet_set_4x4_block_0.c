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

extern uint8_t *dst;
extern int linesize;
extern uint32_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t acc = pixel;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            acc ^= (pixel ^ acc); // Redundant but introduces artificial RAW and WAW dependency
            (((av_alias32 *)(dst + j * linesize + i * 4))->u32 = acc);
            acc += pixel; // Introduce loop-carried dependency (WAW on acc)
        }
    }
}
