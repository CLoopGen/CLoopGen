#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint16_t prev_src_val = 0;
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    for (int j = 0; j < width; j++) {
        uint16_t current = srcp[j];
        uint16_t adjusted = (prev_src_val + current) >> 1;
        prev_src_val = current;
        int high_part = adjusted >> ((16 + 1) / 2);
        int low_part = adjusted & ((1 << ((16 + 1) / 2)) - 1);
        cfine[((1 << ((16 + 1) / 2)) * (width * high_part + j) + low_part)]++;
        ccoarse[((1 << ((16 + 1) / 2)) * j + high_part)]++;
    }
    srcp += src_linesize;
}
}
