#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern  int w;
extern  uint16_t (*tab)[65536];
extern  int step;
extern  int slice_start;
extern  int slice_end;
extern uint8_t *inrow;
extern uint8_t *outrow;
extern uint8_t *inrow0;
extern uint8_t *outrow0;
extern  int in_linesize;
extern  int out_linesize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = slice_start; i < slice_end; i++) {
    inrow = inrow0 + i * in_linesize;
    outrow = outrow0 + i * out_linesize;
    // Use consecutive memory access by unrolling based on maximum step size
    for (j = 0; j < w * step; j += step) {
        // Access elements consecutively using fixed offsets, simulating vectorizable pattern
        outrow[j + 0] = tab[0][inrow[j + 0]];
        if (step > 1) outrow[j + 1] = tab[1][inrow[j + 1]];
        if (step > 2) outrow[j + 2] = tab[2][inrow[j + 2]];
        if (step > 3) outrow[j + 3] = tab[3][inrow[j + 3]];
    }
}
}
