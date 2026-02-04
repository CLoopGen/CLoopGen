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
    for (j = 0; j < w; j += 2) {
        switch (step) {
          case 4:
            outrow[3] = tab[3][inrow[3]];
            if (j + 1 < w) {
                outrow[7] = tab[3][inrow[7]];
            }
          case 3:
            outrow[2] = tab[2][inrow[2]];
            if (j + 1 < w) {
                outrow[6] = tab[2][inrow[6]];
            }
          case 2:
            outrow[1] = tab[1][inrow[1]];
            if (j + 1 < w) {
                outrow[5] = tab[1][inrow[5]];
            }
          default:
            outrow[0] = tab[0][inrow[0]];
            if (j + 1 < w) {
                outrow[4] = tab[0][inrow[4]];
            }
        }
        outrow += step * 2;
        inrow += step * 2;
    }
}
}
