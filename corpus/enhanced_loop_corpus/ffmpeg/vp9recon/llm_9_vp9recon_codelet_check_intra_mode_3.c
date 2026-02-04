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
    int step = (bytesperpixel == 1) ? 4 : 2;
    for (int i = 0; i < n_px_need; i += step) {
        for (int j = 0; j < step && (i + j) < n_px_need; j++) {
            int idx = i + j;
            if (bytesperpixel == 1) {
                l[idx] = dst[idx * stride - 1];
            } else {
                ((av_alias16*)&l[idx * 2])->u16 = ((const av_alias16*)&dst[idx * stride - 2])->u16;
            }
        }
    }
}
