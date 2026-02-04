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
    dwtcoef *restrict s = synthl;
    ptrdiff_t w = synth_width;
    dwtcoef acc = 0;
    for (x = 0; x < w; x++) {
        acc += s[w + x];
        s[x] += (2 * acc + 2) >> 2;
        acc = s[w + x]; // Introduce WAW and WAR dependency
    }
}
