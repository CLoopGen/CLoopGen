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
    ptrdiff_t offset = -stride;
    for (i = 0; i < n_px_need; i++) {
        int idx = i;
        if (bytesperpixel == 1) {
            l[idx] = dst[idx * stride + offset / stride * stride];
        } else {
            av_alias16 *dst_val = (av_alias16*)&dst[idx * stride + offset];
            av_alias16 *l_ptr = (av_alias16*)&l[idx * 2];
            l_ptr->u16 = dst_val->u16;
        }
    }
}
