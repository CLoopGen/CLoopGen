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
    for (int j = 0; j < width; j += 2) {
        uint16_t val1 = srcp[j];
        int shift = (10 + 1) / 2;
        int mask = (1 << shift) - 1;
        int index_fine1 = (1 << shift) * (width * (val1 >> shift) + j) + (val1 & mask);
        ccoarse[(1 << shift) * j + (val1 >> shift)]++;
        if (j + 1 < width) {
            uint16_t val2 = srcp[j + 1];
            int index_fine2 = (1 << shift) * (width * (val2 >> shift) + (j + 1)) + (val2 & mask);
            cfine[index_fine2]++;
            ccoarse[(1 << shift) * (j + 1) + (val2 >> shift)]++;
        }
        cfine[index_fine1]++;
    }
    srcp += src_linesize;
}
}
