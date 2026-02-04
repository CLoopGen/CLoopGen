#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int32_t base_val, scaled_diff;

        // Eliminate nested ternary by predetermining branch using simplified condition
        int32_t twice_t = 2 * t;
        if (t >= 32768) {
            int32_t adjusted = twice_t - 65536; // because 2*(t - 32768) = 2t - 65536
            if (adjusted == 65535) {
                scaled_diff = 65535;
            } else {
                int32_t denom = 65535 - adjusted;
                int32_t temp = (b << 16) / denom;
                scaled_diff = temp < 65535 ? temp : 65535;
            }
        } else {
            if (twice_t == 0) {
                scaled_diff = 0;
            } else {
                int32_t temp = ((65535 - b) << 16) / twice_t;
                scaled_diff = (65535 - temp) > 0 ? (65535 - temp) : 0;
            }
        }

        // Clamp and apply opacity in a single expression
        int32_t blended = t + (int32_t)((scaled_diff - t) * opacity);
        dst[j] = (blended < 0) ? 0 : (blended > 65535 ? 65535 : blended);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
