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
        int idx_fine1 = ((1 << 8) * (width * ((srcp[j] >> 8)) + j) + (srcp[j] & 0xFF));
        int idx_coarse1 = ((1 << 8) * j + (srcp[j] >> 8));
        cfine[idx_fine1]++;
        ccoarse[idx_coarse1]++;
        
        if (j + 1 < width) {
            int idx_fine2 = ((1 << 8) * (width * ((srcp[j+1] >> 8)) + (j+1)) + (srcp[j+1] & 0xFF));
            int idx_coarse2 = ((1 << 8) * (j+1) + (srcp[j+1] >> 8));
            cfine[idx_fine2]++;
            ccoarse[idx_coarse2]++;
        }
    }
    srcp += src_linesize;
}
}
