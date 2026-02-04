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
    int j = 0;
    for (; j < width; j += 2) {
        if (j + 1 < width) {
            // Process two elements per iteration: j and j+1
            int offset_fine1 = ((1 << ((10 + 1) / 2)) * ((width) * ((srcp[j]) >> ((10 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((10 + 1) / 2)) - 1)));
            int offset_coarse1 = ((1 << ((10 + 1) / 2)) * (j) + ((srcp[j]) >> ((10 + 1) / 2)));
            cfine[offset_fine1]++;
            ccoarse[offset_coarse1]++;

            int offset_fine2 = ((1 << ((10 + 1) / 2)) * ((width) * ((srcp[j+1]) >> ((10 + 1) / 2)) + (j+1)) + ((srcp[j+1]) & ((1 << ((10 + 1) / 2)) - 1)));
            int offset_coarse2 = ((1 << ((10 + 1) / 2)) * (j+1) + ((srcp[j+1]) >> ((10 + 1) / 2)));
            cfine[offset_fine2]++;
            ccoarse[offset_coarse2]++;
        } else {
            // Handle last element if width is odd
            int offset_fine = ((1 << ((10 + 1) / 2)) * ((width) * ((srcp[j]) >> ((10 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((10 + 1) / 2)) - 1)));
            int offset_coarse = ((1 << ((10 + 1) / 2)) * (j) + ((srcp[j]) >> ((10 + 1) / 2)));
            cfine[offset_fine]++;
            ccoarse[offset_coarse]++;
        }
    }
    srcp += src_linesize;
}
}
