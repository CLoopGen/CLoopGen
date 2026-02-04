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
// Eliminate all loop-carried dependencies and make operations fully parallelizable
// Remove any intra-loop state; ensure each j iteration is independent
// Also restructure conditionals into precomputed lookup hints to reduce branching cost

for (i = 0; i < height; i++) {
    // Precompute invariant terms outside inner loop to break potential WAR/WAW with outer loop updates
    uint16_t* local_dst = dst;
    uint16_t* local_top = top;
    uint16_t* local_bottom = bottom;

    for (j = 0; j < width; j++) {
        uint16_t t = local_top[j];
        uint16_t b = local_bottom[j];
        int result;

        if (t < 32768) {
            int twice_t = 2 * t;
            if (twice_t == 0) {
                result = t + (twice_t - t) * opacity;
            } else {
                int diff_term = (65535 - b) << 16;
                int div_result = diff_term / twice_t;
                int clamped_val = (0 > (65535 - div_result)) ? 0 : (65535 - div_result);
                result = t + (clamped_val - t) * opacity;
            }
        } else {
            int adjusted = 2 * (t - 32768);
            if (adjusted == 65535) {
                result = t + (adjusted - t) * opacity;
            } else {
                int denom = 65535 - adjusted;
                int num = (b << 16);
                int div_result = num / denom;
                int clamped_val = (65535 > div_result) ? div_result : 65535;
                result = t + (clamped_val - t) * opacity;
            }
        }

        local_dst[j] = (uint16_t)result;
    }

    // Update pointers only once per outer loop iteration to avoid interference in inner loop
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
