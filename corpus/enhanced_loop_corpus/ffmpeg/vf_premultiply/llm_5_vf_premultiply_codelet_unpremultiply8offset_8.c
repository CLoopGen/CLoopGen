#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int offset;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        uint8_t alpha = asrc[x];
        uint8_t mval = msrc[x];
        uint8_t base = (mval > offset) ? (mval - offset) : 0;
        int computed;

        // Eliminate nested conditionals using arithmetic logic
        int is_alpha_opaque = (alpha == 255);
        int is_alpha_transparent = (alpha == 0);

        // Transparent: use mval; Opaque: use clamped value + offset capped at 255; Otherwise: scale by alpha
        computed = is_alpha_transparent ? mval :
                   is_alpha_opaque ? ((base + offset) > 255 ? 255 : base + offset) :
                   ((base * 255 / alpha + offset) > 255 ? 255 : base * 255 / alpha + offset);

        dst[x] = (uint8_t)computed;
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
