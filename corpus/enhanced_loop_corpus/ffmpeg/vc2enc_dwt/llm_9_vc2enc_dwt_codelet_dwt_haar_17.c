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
    for (y = 0; y < synth_height; y += 2) {
        if (y + 1 < synth_height) {
            for (x = 0; x < synth_width; x += 2) {
                dwtcoef val_a1 = datal[y * stride + x + 1] << s;
                dwtcoef val_a2 = datal[y * stride + x] << s;
                dwtcoef diff_a = val_a1 - val_a2;
                synthl[y * synth_width + x + 1] = diff_a;
                synthl[y * synth_width + x] = val_a2 + ((diff_a + 1) >> 1);

                dwtcoef val_b1 = datal[(y + 1) * stride + x + 1] << s;
                dwtcoef val_b2 = datal[(y + 1) * stride + x] << s;
                dwtcoef diff_b = val_b1 - val_b2;
                synthl[(y + 1) * synth_width + x + 1] = diff_b;
                synthl[(y + 1) * synth_width + x] = val_b2 + ((diff_b + 1) >> 1);
            }
        } else {
            for (x = 0; x < synth_width; x += 2) {
                synthl[y * synth_width + x + 1] = (datal[y * stride + x + 1] << s) - (datal[y * stride + x] << s);
                synthl[y * synth_width + x] = (datal[y * stride + x] << s) + ((synthl[y * synth_width + x + 1] + 1) >> 1);
            }
        }
    }
}
