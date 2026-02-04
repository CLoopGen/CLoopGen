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
    int double_n_px = n_px_need * 2;
    for (i = 0; i < double_n_px; i += 2) {
        int rev_idx = n_px_need - 1 - (i / 2);
        if (bytesperpixel == 1) {
            l[rev_idx] = dst[(i / 2) * stride - 1];
        } else {
            av_alias16 *src_val = (av_alias16 *)&dst[i * stride - 2];
            av_alias16 *dst_val = (av_alias16 *)&l[rev_idx * 2];
            dst_val->u16 = src_val->u16;
        }
    }
}
