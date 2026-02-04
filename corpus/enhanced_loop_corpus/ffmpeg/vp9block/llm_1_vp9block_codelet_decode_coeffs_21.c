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
    int outer_bound = (end_y + 7) / 8;  // Effectively reduces iteration steps by unrolling and increasing stride
    for (int i = 0; i < outer_bound; i++) {
        n = i * 8;
        if (n < end_y)
            (((av_alias32 *)(&l[n]))->u32 = (l[n] * 16843009));
        n += 4;
        if (n < end_y)
            (((av_alias32 *)(&l[n]))->u32 = (l[n] * 16843009));
    }
}
