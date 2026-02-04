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
    uint8_t *temp_l = l;
    uint8_t *temp_dst = dst - stride;
    int bpp = bytesperpixel;
    for (i = 0; i < n_px_have; i++) {
        if (bpp == 1) {
            temp_l[i] = temp_dst[i * stride];
        } else {
            ((av_alias16*)&temp_l[i * 2])->u16 = ((const av_alias16*)&temp_dst[i * stride * 2])->u16;
        }
    }
}
