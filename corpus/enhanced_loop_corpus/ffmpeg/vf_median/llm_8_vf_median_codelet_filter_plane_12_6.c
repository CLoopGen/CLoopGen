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
        int idx_fine_1 = ((1 << ((12 + 1) / 2)) * ((width) * ((srcp[j]) >> ((12 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((12 + 1) / 2)) - 1)));
        int idx_coarse_1 = ((1 << ((12 + 1) / 2)) * (j) + ((srcp[j]) >> ((12 + 1) / 2)));
        cfine[idx_fine_1]++;
        ccoarse[idx_coarse_1]++;

        if (j + 1 < width) {
            int idx_fine_2 = ((1 << ((12 + 1) / 2)) * ((width) * ((srcp[j+1]) >> ((12 + 1) / 2)) + (j+1)) + ((srcp[j+1]) & ((1 << ((12 + 1) / 2)) - 1)));
            int idx_coarse_2 = ((1 << ((12 + 1) / 2)) * (j+1) + ((srcp[j+1]) >> ((12 + 1) / 2)));
            cfine[idx_fine_2]++;
            ccoarse[idx_coarse_2]++;
        }
    }
    srcp += src_linesize;
}
}
