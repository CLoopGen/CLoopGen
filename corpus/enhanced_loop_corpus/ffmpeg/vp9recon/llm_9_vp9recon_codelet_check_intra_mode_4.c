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
extern int i;
extern int n_px_have;
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (bytesperpixel == 1) ? 4 : 2;
    for (i = 0; i < n_px_have; i += step) {
        if (bytesperpixel == 1) {
            l[i] = dst[i * stride - 1];
            if (i + 1 < n_px_have) l[i + 1] = dst[(i + 1) * stride - 1];
            if (i + 2 < n_px_have) l[i + 2] = dst[(i + 2) * stride - 1];
            if (i + 3 < n_px_have) l[i + 3] = dst[(i + 3) * stride - 1];
        } else {
            ((av_alias16*)&l[i * 2])->u16 = ((const av_alias16*)&dst[i * stride - 2])->u16;
            if (i + 1 < n_px_have) {
                ((av_alias16*)&l[(i + 1) * 2])->u16 = ((const av_alias16*)&dst[(i + 1) * stride - 2])->u16;
            }
        }
    }
}
