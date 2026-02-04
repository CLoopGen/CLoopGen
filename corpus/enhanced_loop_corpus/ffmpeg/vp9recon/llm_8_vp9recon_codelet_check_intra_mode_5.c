#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t *l;
extern int n_px_need;
extern int n_px_have;
extern int n;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < (n_px_need - n_px_have); i += 2) {
        if ((i + n_px_have) * 2 + 1 < (size_t)(-1) / sizeof(uint8_t)) {
            (((av_alias16 *)(&(l)[((n_px_have) + i) * 2]))->u16 = (val));
            if (i + 1 < (n_px_need - n_px_have)) {
                (((av_alias16 *)(&(l)[((n_px_have) + i + 1) * 2]))->u16 = (val));
            }
        }
    }
}
