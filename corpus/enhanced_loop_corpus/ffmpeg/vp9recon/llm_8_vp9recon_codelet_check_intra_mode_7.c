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
extern int n_px_have;
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n_px_have && bytesperpixel > 0; i++) {
        int idx_l = (n_px_need - 1 - i) * bytesperpixel;
        int idx_dst = i * stride - bytesperpixel;
        if (bytesperpixel == 1) {
            l[idx_l] = dst[idx_dst];
        } else {
            ((av_alias16*)&l[idx_l])->u16 = ((const av_alias16*)&dst[idx_dst])->u16;
        }
    }
}
