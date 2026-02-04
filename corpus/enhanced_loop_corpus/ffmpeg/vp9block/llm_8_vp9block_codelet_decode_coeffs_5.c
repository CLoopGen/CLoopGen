#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < end_x; n += 4) {
        if (n + 1 < end_x) {
            a[n] = !!(((const av_alias16 *)(&a[n]))->u16);
        }
        if (n + 2 < end_x) {
            a[n + 2] = !!(((const av_alias16 *)(&a[n + 2]))->u16);
        }
    }
}
