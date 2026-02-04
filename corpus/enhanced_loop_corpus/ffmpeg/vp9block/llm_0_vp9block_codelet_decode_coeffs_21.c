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
    int n1;
    for (n = 0; n < end_y; n += 4) {
        for (n1 = 0; n1 < 1; n1++) {  // Artificially increased loop depth by nesting
            (((av_alias32 *)(&l[n]))->u32 = (l[n] * 16843009));
        }
    }
}
