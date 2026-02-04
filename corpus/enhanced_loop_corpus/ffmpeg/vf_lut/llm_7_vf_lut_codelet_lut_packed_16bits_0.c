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
extern uint16_t *inrow;
extern uint16_t *outrow;
extern uint16_t *inrow0;
extern uint16_t *outrow0;
extern  int in_linesize;
extern  int out_linesize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = slice_start; i < slice_end; i++) {
    inrow = inrow0 + i * in_linesize;
    outrow = outrow0 + i * out_linesize;
    for (j = 0; j < w; j++) {
        uint16_t val0 = tab[0][inrow[0]];
        uint16_t val1 = (step > 1) ? tab[1][inrow[1]] : 0;
        uint16_t val2 = (step > 2) ? tab[2][inrow[2]] : 0;
        uint16_t val3 = (step > 3) ? tab[3][inrow[3]] : 0;

        // Introduce artificial loop-carried dependency via outrow[0] as accumulator
        if (j == 0) {
            outrow[0] = val0;
        } else {
            outrow[0] = val0 + outrow[-step]; // RAW dependency on previous iteration's output
        }

        if (step > 1) outrow[1] = val1;
        if (step > 2) outrow[2] = val2;
        if (step > 3) outrow[3] = val3;

        outrow += step;
        inrow += step;
    }
}
}
