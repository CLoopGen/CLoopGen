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
    for (int i = 0; i < end_x; i += 8) {
        for (int j = 0; j < 1; j++) { // Artificially increased loop depth by nesting
            (((av_alias32 *)(&a[i]))->u32 = (a[i] * 16843009));
        }
    }
}
