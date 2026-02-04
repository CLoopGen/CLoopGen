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
    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            uint16_t val = srcp[j];
            int shift = (14 + 1) / 2;
            int mask = (1 << shift) - 1;
            int coarse_index = (1 << shift) * j + (val >> shift);
            int fine_index = (1 << shift) * (width * (val >> shift) + j) + (val & mask);

            if ((val & 0x1) && (j % 2 == 0)) {
                cfine[fine_index]++;
            } else {
                ccoarse[coarse_index]++;
            }
        }
        srcp += src_linesize;
    }
}
