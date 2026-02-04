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
    if (n_px_need > n_px_have) {
        n = 0;
        for (int i = 0; i < (n_px_need - n_px_have); i += 8) {
            for (int j = 0; j < 8 && n < (n_px_need - n_px_have); j++, n++) {
                (((av_alias16 *)(&(l)[((n_px_have) + n) * 2]))->u16 = (val));
            }
        }
    }
}
