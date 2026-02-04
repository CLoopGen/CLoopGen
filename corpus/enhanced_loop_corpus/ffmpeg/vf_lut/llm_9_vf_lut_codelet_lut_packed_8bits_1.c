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
for (i = slice_start; i < slice_end; i += 2) {
    for (j = 0; j < w; j++) {
        uint8_t *inrow1 = inrow0 + (i + 1) * in_linesize;
        uint8_t *outrow1 = outrow0 + (i + 1) * out_linesize;
        inrow = inrow0 + i * in_linesize;
        outrow = outrow0 + i * out_linesize;

        switch (step) {
          case 4:
            outrow[3] = tab[3][inrow[3]];
            if (i + 1 < slice_end) outrow1[3] = tab[3][inrow1[3]];
          case 3:
            outrow[2] = tab[2][inrow[2]];
            if (i + 1 < slice_end) outrow1[2] = tab[2][inrow1[2]];
          case 2:
            outrow[1] = tab[1][inrow[1]];
            if (i + 1 < slice_end) outrow1[1] = tab[1][inrow1[1]];
          default:
            outrow[0] = tab[0][inrow[0]];
            if (i + 1 < slice_end) outrow1[0] = tab[0][inrow1[0]];
        }
        outrow += step;
        inrow += step;
        if (i + 1 < slice_end) {
            outrow1 += step;
            inrow1 += step;
        }
    }
}
}
