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
    for (y = 1; y < height - 1; y++) {
        dwtcoef *prev_row = synthl;
        dwtcoef *curr_row = synthl + synth_width;
        dwtcoef *next_row = synthl + (synth_width << 1);
        for (x = 0; x < synth_width; x++) {
            dwtcoef prediction = (prev_row[x] + next_row[x] + 1) >> 1;
            curr_row[x] -= prediction;
        }
        synthl += (synth_width << 1);
    }
}
