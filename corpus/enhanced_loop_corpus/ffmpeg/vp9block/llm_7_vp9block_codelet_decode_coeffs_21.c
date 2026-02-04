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
    for (n = 0; n < end_y; n += 4) {
        uint32_t val = (uint32_t)l[n] * 16843009;
        ((av_alias32 *)(&l[n + 1]))->u32 = val; // Introduce WAW and WAR dependency by writing ahead
        ((av_alias32 *)(&l[n]))->u32 = val;    // Original write, now creates loop-carried WAW if unrolled
    }
}
