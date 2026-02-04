#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern dwtcoef *datal;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dwtcoef *temp_synthl = synthl;
    dwtcoef *temp_datal = datal;
    for (y = 0; y < synth_height; y++) {
        dwtcoef prev_val = 0;
        for (x = 0; x < synth_width; x++) {
            dwtcoef current = temp_datal[x] << 1;
            temp_synthl[x] = current + prev_val;
            prev_val = current;
        }
        temp_synthl += synth_width;
        temp_datal += stride;
    }
}
