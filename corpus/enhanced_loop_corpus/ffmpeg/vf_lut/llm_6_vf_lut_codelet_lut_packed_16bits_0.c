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
    uint16_t temp0, temp1, temp2, temp3;
    for (j = 0; j < w; j++) {
        switch (step) {
          case 4:
            temp3 = tab[3][inrow[3]];
            outrow[3] = temp3;
          case 3:
            temp2 = tab[2][inrow[2]];
            outrow[2] = temp2;
          case 2:
            temp1 = tab[1][inrow[1]];
            outrow[1] = temp1;
          default:
            temp0 = tab[0][inrow[0]];
            outrow[0] = temp0;
        }
        outrow += step;
        inrow += step;
    }
}
}
