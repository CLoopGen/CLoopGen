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
for (i = slice_start; i < slice_end; i += 2) {
    inrow = inrow0 + i * in_linesize;
    outrow = outrow0 + i * out_linesize;
    for (j = 0; j < w; j++) {
        switch (step) {
          case 4:
            outrow[3] = tab[3][inrow[3]];
            if (i + 1 < slice_end) {
                uint16_t* inrow_next = inrow0 + (i+1) * in_linesize + j * step;
                uint16_t* outrow_next = outrow0 + (i+1) * out_linesize + j * step;
                outrow_next[3] = tab[3][inrow_next[3]];
            }
          case 3:
            outrow[2] = tab[2][inrow[2]];
            if (i + 1 < slice_end) {
                uint16_t* inrow_next = inrow0 + (i+1) * in_linesize + j * step;
                uint16_t* outrow_next = outrow0 + (i+1) * out_linesize + j * step;
                outrow_next[2] = tab[2][inrow_next[2]];
            }
          case 2:
            outrow[1] = tab[1][inrow[1]];
            if (i + 1 < slice_end) {
                uint16_t* inrow_next = inrow0 + (i+1) * in_linesize + j * step;
                uint16_t* outrow_next = outrow0 + (i+1) * out_linesize + j * step;
                outrow_next[1] = tab[1][inrow_next[1]];
            }
          default:
            outrow[0] = tab[0][inrow[0]];
            if (i + 1 < slice_end) {
                uint16_t* inrow_next = inrow0 + (i+1) * in_linesize + j * step;
                uint16_t* outrow_next = outrow0 + (i+1) * out_linesize + j * step;
                outrow_next[0] = tab[0][inrow_next[0]];
            }
        }
        outrow += step;
        inrow += step;
    }
}
}
