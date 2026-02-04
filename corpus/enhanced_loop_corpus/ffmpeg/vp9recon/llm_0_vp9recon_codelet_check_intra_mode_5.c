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
    int outer_n;
    for (outer_n = 0; outer_n < (n_px_need - n_px_have + 1) / 2; outer_n++) {
        for (n = outer_n * 2; n < (n_px_need - n_px_have) && n < (outer_n + 1) * 2; n++) {
            (((av_alias16 *)(&(l)[((n_px_have) + n) * 2]))->u16 = (val));
        }
    }
}
