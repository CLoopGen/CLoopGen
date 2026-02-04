#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int height;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < height - 2; y++) {
    dwtcoef *s = synthl;
    for (x = 0; x < synth_width; x += 2) {
        // Unrolled with stride-2 access to improve spatial locality and enable potential vectorization
        if (x + 1 < synth_width) {
            s[synth_width]     -= (9 * s[0] + 9 * s[2 * synth_width] - 
                                   s[-2 * synth_width] - s[4 * synth_width] + 8) >> 4;
            s[synth_width + 1] -= (9 * s[1] + 9 * s[2 * synth_width + 1] - 
                                   s[-2 * synth_width + 1] - s[4 * synth_width + 1] + 8) >> 4;
        } else {
            s[synth_width]     -= (9 * s[0] + 9 * s[2 * synth_width] - 
                                   s[-2 * synth_width] - s[4 * synth_width] + 8) >> 4;
        }
        s++;
    }
    synthl += synth_width << 1;
}
}
