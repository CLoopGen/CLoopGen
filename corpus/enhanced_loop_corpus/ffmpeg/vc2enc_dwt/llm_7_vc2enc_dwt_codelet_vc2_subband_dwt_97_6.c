#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int x;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dwtcoef *l_synthl = synthl;
    ptrdiff_t l_synth_width = synth_width;

    if (l_synth_width > 0) {
        l_synthl[0] += (l_synthl[l_synth_width] + l_synthl[l_synth_width] + 2) >> 2;
        for (x = 1; x < l_synth_width; x++) {
            l_synthl[x] += (l_synthl[x + l_synth_width] + l_synthl[x - 1 + l_synth_width] + 2) >> 2;
        }
    }
}
