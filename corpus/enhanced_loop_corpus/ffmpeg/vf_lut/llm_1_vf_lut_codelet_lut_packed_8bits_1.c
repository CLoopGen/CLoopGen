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
    for (j = 0; j < w; j++) {
        int k;
        for (k = 0; k < step && k < 4; k++) {
            outrow[k] = tab[k][inrow[k]];
        }
        outrow += step;
        inrow += step;
    }
}
}
