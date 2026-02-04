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
        if (j + 1 < width) {
            // Strided access: process two elements per iteration with step of 2
            int idx0_fine = ((1 << ((16 + 1) / 2)) * ((width) * ((srcp[j]) >> ((16 + 1) / 2)) + j) + ((srcp[j]) & ((1 << ((16 + 1) / 2)) - 1)));
            int idx1_fine = ((1 << ((16 + 1) / 2)) * ((width) * ((srcp[j+1]) >> ((16 + 1) / 2)) + (j+1)) + ((srcp[j+1]) & ((1 << ((16 + 1) / 2)) - 1)));
            cfine[idx0_fine]++;
            cfine[idx1_fine]++;

            int idx0_coarse = ((1 << ((16 + 1) / 2)) * j + ((srcp[j]) >> ((16 + 1) / 2)));
            int idx1_coarse = ((1 << ((16 + 1) / 2)) * (j+1) + ((srcp[j+1]) >> ((16 + 1) / 2)));
            ccoarse[idx0_coarse]++;
            ccoarse[idx1_coarse]++;
        } else {
            // Handle last element if width is odd
            int idx_fine = ((1 << ((16 + 1) / 2)) * ((width) * ((srcp[j]) >> ((16 + 1) / 2)) + j) + ((srcp[j]) & ((1 << ((16 + 1) / 2)) - 1)));
            cfine[idx_fine]++;
            int idx_coarse = ((1 << ((16 + 1) / 2)) * j + ((srcp[j]) >> ((16 + 1) / 2)));
            ccoarse[idx_coarse]++;
        }
    }
    srcp += src_linesize;
}
}
