#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int width;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y++) {
    dwtcoef *ptr = synthl;
    ptrdiff_t step = 2;
    for (int i = 0; i < synth_width; i += step) {
        if (i == 0 && width > 2)
            ptr[1] -= (8 * ptr[0] + 9 * ptr[2] - ptr[4] + 8) >> 4;
        else if (i > 0 && i < synth_width - 4 && i/step < width - 2)
            ptr[i + 1] -= (9 * ptr[i] + 9 * ptr[i + 2] - ptr[i + 4] - ptr[i - 2] + 8) >> 4;
    }
    if (synth_width >= 1) ptr[synth_width - 1] -= (17 * ptr[synth_width - 2] - ptr[synth_width - 4] + 8) >> 4;
    if (synth_width >= 3) ptr[synth_width - 3] -= (8 * ptr[synth_width - 2] + 9 * ptr[synth_width - 4] - ptr[synth_width - 6] + 8) >> 4;
    ptr[0] += (ptr[1] + ptr[1] + 2) >> 2;
    for (int i = 2; i < synth_width - 2 && i/2 < width - 1; i += 2)
        ptr[i] += (ptr[i - 1] + ptr[i + 1] + 2) >> 2;
    if (synth_width >= 2) ptr[synth_width - 2] += (ptr[synth_width - 3] + ptr[synth_width - 1] + 2) >> 2;
    synthl += synth_width;
}
}
