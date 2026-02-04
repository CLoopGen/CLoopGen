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
    for (int i = 0; i < n_px_need; i += 2) {
        if (bytesperpixel == 1) {
            l[i] = dst[i * stride - 1];
            if (i + 1 < n_px_need) {
                l[i + 1] = dst[(i + 1) * stride - 1];
            }
        } else {
            av_alias16 *dst_val1 = (av_alias16*)&dst[i * stride - 2];
            av_alias16 *l_store1 = (av_alias16*)&l[i * 2];
            l_store1->u16 = dst_val1->u16;
            if (i + 1 < n_px_need) {
                av_alias16 *dst_val2 = (av_alias16*)&dst[(i + 1) * stride - 2];
                av_alias16 *l_store2 = (av_alias16*)&l[(i + 1) * 2];
                l_store2->u16 = dst_val2->u16;
            }
        }
    }
}
