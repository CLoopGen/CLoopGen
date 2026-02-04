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
    int j;
    for (i = 0; i < n_px_need; i++) {
        j = n_px_need - 1 - i;
        if (bytesperpixel == 1) {
            l[j] = dst[i * stride - 1];
        } else {
            ((av_alias16 *)(l + j * 2))->u16 = ((const av_alias16 *)(dst + i * stride * 2 - 2))->u16;
        }
    }
}
