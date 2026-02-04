#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t *l;
extern int bytesperpixel;
extern int n_px_need;
extern int i;
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n_px_need > 0) {
        for (i = n_px_need - 1; i >= 0; i--) {
            if (bytesperpixel == 1) {
                (l)[(n_px_need - 1 - i)] = (&dst[(n_px_need - 1 - i) * stride])[(-1)];
            } else {
                (((av_alias16 *)(&(l)[(n_px_need - 1 - i) * 2]))->u16 = ((const av_alias16 *)(&(&dst[(n_px_need - 1 - i) * stride])[(-1) * 2]))->u16);
            }
        }
    }
}
