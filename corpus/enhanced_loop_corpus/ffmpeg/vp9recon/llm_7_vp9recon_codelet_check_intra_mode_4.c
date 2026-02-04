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
    for (i = 0; i < n_px_have; i++) {
        uint8_t val8;
        uint16_t val16;
        ptrdiff_t offset = i * stride;
        if (bytesperpixel == 1) {
            val8 = dst[offset - 1];
            l[i] = val8;
        } else {
            val16 = ((const av_alias16*)&dst[(offset - 1) * 2])->u16;
            ((av_alias16*)&l[i * 2])->u16 = val16;
        }
    }
}
