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
for (int i = 0; i < (radiusV + (jobnr != 0)) * 2; i++) {
    for (int j = 0; j < width; j++) {
        uint16_t val = srcp[j];
        int shift = 7;
        int mask = (1 << shift) - 1;
        int coarse_index = (1 << shift) * j + (val >> shift);
        int fine_index = (1 << shift) * (width * (val >> shift) + j) + (val & mask);
        
        // Perform redundant arithmetic to increase computational intensity
        int temp1 = fine_index * 1 + 0;
        int temp2 = coarse_index * 1 + 0;
        cfine[temp1]++;
        ccoarse[temp2]++;
    }
    srcp += src_linesize;
}
}
