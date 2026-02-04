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
    for (int i = 0; i < end_x; i++) {
        if (i % 2 == 0) {
            n = i;
            a[n] = !!(((const av_alias16 *)(&a[n]))->u16);
        }
    }
}
