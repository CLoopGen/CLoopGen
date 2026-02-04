#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern  int s;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern dwtcoef *datal;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < synth_height; y++) {
        for (int offset = 0; offset < synth_width; offset += 2) {
            int idx_datal = y * stride + offset;
            int idx_synthl = y * synth_width + offset;
            dwtcoef temp = (datal[idx_datal + 1] << s) - (datal[idx_datal] << s);
            synthl[idx_synthl + 1] = temp;
            synthl[idx_synthl] = (datal[idx_datal] << s) + ((temp + 1) >> 1);
        }
    }
}
