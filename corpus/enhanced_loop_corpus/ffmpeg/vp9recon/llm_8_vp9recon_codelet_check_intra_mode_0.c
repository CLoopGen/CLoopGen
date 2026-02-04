#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t **a;
extern int n_px_need;
extern int n_px_have;
extern int n;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (n = 0; n < (n_px_need - n_px_have); n += step) {
        (((av_alias16 *)(&(*a)[((n_px_have) + n) * 2]))->u16 = (val));
        if (n + 1 < (n_px_need - n_px_have)) {
            (((av_alias16 *)(&(*a)[((n_px_have) + n + 1) * 2]))->u16 = (val));
        }
    }
}
