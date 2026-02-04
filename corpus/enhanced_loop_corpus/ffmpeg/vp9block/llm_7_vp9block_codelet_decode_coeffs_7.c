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
    uint32_t prev_val = 0;
    for (n = 0; n < end_x; n += 2) {
        uint32_t computed = (a[n] + (prev_val & 0xFF)) * 16843009;
        (((av_alias32 *)(&a[n]))->u32 = computed);
        prev_val = computed;
    }
}
